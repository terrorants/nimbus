#include "nv.h"
#include "stm32f4xx.h"
#include "flash_api.h"
#include "logger.h"
#include "tmr.h"

#define NV_MAGIC_WORD 0x57012A63

#define NV_AREA0_START  (0x80C0000)
#define NV_AREA0_SIZE   (128 * 1024) // 128K
#define NV_AREA0_END    (NV_AREA0_START + NV_AREA0_SIZE)
#define NV_AREA0_SECTOR (FLASH_SECTOR_10)
#define NV_AREA1_START  (NV_AREA0_START + NV_AREA0_SIZE)
#define NV_AREA1_SIZE   (NV_AREA0_SIZE)
#define NV_AREA1_END    (NV_AREA1_START + NV_AREA1_SIZE)
#define NV_AREA1_SECTOR (FLASH_SECTOR_11)

#define RAM_VAR_ENTRY(id, var)               { id, sizeof(var), &var }

typedef enum
{
  NV_STATUS_ok = 0,
  NV_STATUS_area_full
} nv_status_e;

typedef struct
{
  uint32_t startAddr;
  uint32_t endAddr;
  uint32_t sector;
} nv_attr_s;

typedef struct __attribute__((packed))
{
  uint32_t magic;
  uint32_t counter;
} nv_area_hdr_s;

typedef struct __attribute__((packed))
{
  nv_area_hdr_s hdr;
  uint8_t       data[];
} nv_area_s;

typedef struct __attribute__((packed))
{
  uint16_t id;   /**< Variable ID */
  uint16_t size; /**< Size (in bytes) of data portion. */
} nv_var_hdr_s;

typedef struct __attribute__((packed))
{
  nv_var_hdr_s hdr;
  uint8_t      data[];
} nv_var_s;

typedef struct
{
  const uint16_t id;
  const int16_t  size; /**< Specify -1 to signal size-check bypass. */
  void           *data;
  nv_var_s       *nv_var;
} ram_var_s;

typedef struct
{
  uint32_t     headAddress;
  uint32_t     tailAddress; /**< End of known data to append to. */
  nv_area_e    activeArea;
  uint32_t     counter;
} nv_control_s;

typedef struct 
{
  uint8_t reserved;  
} nv_vars_s;


static const nv_attr_s nvAreas[] =
{
  // NV Area 0
  {
    .startAddr = NV_AREA0_START,
    .endAddr = NV_AREA0_END,
    .sector = NV_AREA0_SECTOR
  },
  // NV Area 1
  {
    .startAddr = NV_AREA1_START,
    .endAddr = NV_AREA1_END,
    .sector = NV_AREA1_SECTOR
  }
};

static nv_control_s nvCtrl;
ram_var_s nvVarLUT[] =
{
  RAM_VAR_ENTRY(NV_ID_LOGGER_LEVELS, logger_levels),
  { NV_ID_INVALID, 0, NULL }
};

static void nv_update_ram_entry(nv_var_s *var)
{
  uint16_t sz;
  ram_var_s *r = &nvVarLUT[0];

  while (r->id != NV_ID_INVALID)
  {
    if (r->id == var->hdr.id)
    {
      // min(r, var) sizes
      sz = var->hdr.size > r->size ? r->size : var->hdr.size;
      memset(r->data, 0, r->size);
      memcpy(r->data, var->data, sz);
      r->nv_var = var;
      break;
    }
    r++;
  }
}

static nv_status_e nv_write_var(uint16_t id, uint8_t *pData, uint16_t size)
{
  uint32_t hdrAddr = nvCtrl.tailAddress;
  nv_var_hdr_s hdr;
  nv_var_s *var = (nv_var_s *)hdrAddr;

  if (nvCtrl.tailAddress + sizeof(nv_var_hdr_s) + size > nvAreas[nvCtrl.activeArea].endAddr)
  {
    return NV_STATUS_area_full;
  }

  Flash_WriteBytes((uint32_t)var->data, pData, size);

  // Write header last in case data-write fails
  hdr.id = id;
  hdr.size = size;
  Flash_WriteBytes(hdrAddr, (uint8_t *)&hdr, sizeof(hdr));

  nvCtrl.tailAddress += sizeof(nv_var_hdr_s) + size;

  nv_update_ram_entry(var);

  return NV_STATUS_ok;
}

static void nv_commit_ram_to_flash(void)
{
  ram_var_s *r = &nvVarLUT[0];

  while (r->id != NV_ID_INVALID)
  {
    nv_write_var(r->id, r->data, r->size);

    r++;
  }
}

static void nv_load_vars(void)
{
  uint32_t address = (uint32_t)((nv_area_s *)nvAreas[nvCtrl.activeArea].startAddr)->data;
  uint32_t endAddress = nvAreas[nvCtrl.activeArea].endAddr;

  nvCtrl.headAddress = address;

  nv_var_s *var = (nv_var_s *)address;

  while (var->hdr.id != NV_ID_INVALID && address < endAddress)
  {
    LOG(FLSH, INFO, "addr 0x%08X, id %d, size %d", var, var->hdr.id, var->hdr.size);

    nv_update_ram_entry(var);

    address += sizeof(nv_var_hdr_s) + var->hdr.size;

    var = (nv_var_s *)address;
  }

  nvCtrl.tailAddress = address;
}

void NV_Init(void)
{
  nv_area_hdr_s *hdr;
  uint8_t i, higherIdx;
  int64_t maxCtr = -1;

  for (i = NV_AREA_0; i < NV_AREA_MAX; i++)
  {
    hdr = (nv_area_hdr_s *)nvAreas[i].startAddr;

    LOG(FLSH, INFO, "addr 0x%08X, hdr->magic 0x%08X, hdr->counter 0x%08X", nvAreas[i].startAddr, hdr->magic, hdr->counter);
    if (hdr->magic == NV_MAGIC_WORD && (int64_t)hdr->counter > maxCtr)
    {
      higherIdx = i;
      maxCtr = hdr->counter;
    }
  }

  if (maxCtr == -1)
  {
    LOG(FLSH, WARNING, "No valid NV areas found. Creating.");
    NV_Reset();
    nvCtrl.activeArea = NV_AREA_0;
    nvCtrl.counter = 0;
  }
  else
  {
    nvCtrl.activeArea = (nv_area_e)higherIdx;
    nvCtrl.counter = maxCtr;
  }

  nv_load_vars();

  LOG(FLSH, INFO, "activeArea = %d", nvCtrl.activeArea);
  LOG(FLSH, INFO, "counter = %d", nvCtrl.counter);
  LOG(FLSH, INFO, "tailAddress = 0x%08X", nvCtrl.tailAddress);
  LOG(FLSH, INFO, "headAddress = 0x%08X", nvCtrl.headAddress);
}

static void nv_write_area_header(nv_area_e area, uint32_t counter)
{
  nv_area_hdr_s hdr;

  hdr.magic = NV_MAGIC_WORD;
  hdr.counter = counter;

  Flash_WriteBytes(nvAreas[area].startAddr, (uint8_t *)&hdr, sizeof(hdr));

  nvCtrl.activeArea = area;
  nvCtrl.counter = counter;
  nvCtrl.headAddress = (uint32_t)((nv_area_s *)nvAreas[area].startAddr)->data;
  nvCtrl.tailAddress = nvCtrl.headAddress;
}

static void nv_format_area(nv_area_e area, uint32_t counter)
{
  Flash_EraseSector(nvAreas[area].sector);

  nv_write_area_header(area, counter);
}

nv_area_e NV_SwitchArea(void)
{
  nv_area_e newArea;

  if (nvCtrl.activeArea == NV_AREA_0)
  {
    newArea = NV_AREA_1;
  }
  else // if (nvCtrl.activeArea == NV_AREA_1)
  {
    newArea = NV_AREA_0;
  }

  nv_format_area(newArea, nvCtrl.counter + 1);

  nv_commit_ram_to_flash();

  return newArea;
}

void NV_Reset(void)
{
  uint32_t start = tmrNow();
  Flash_EraseSector(NV_AREA0_SECTOR);
  LOG(FLSH, INFO, "NV AREA0 erase took %dms", tmrElapsedMs(start));

  start = tmrNow();
  Flash_EraseSector(NV_AREA1_SECTOR);
  LOG(FLSH, INFO, "NV AREA1 erase took %dms", tmrElapsedMs(start));

  nv_write_area_header(NV_AREA_0, 0);
}

bool NV_Read(uint16_t id, uint8_t *data, uint16_t *sz)
{
  return false;
}

bool NV_Write(uint16_t id, uint8_t *data, uint16_t sz)
{
  nv_status_e status = nv_write_var(id, data, sz);

  if (status == NV_STATUS_area_full)
  {
    NV_SwitchArea();
    
    // Try again
    status = nv_write_var(id, data, sz);    
  }

  return status == NV_STATUS_ok;
}
