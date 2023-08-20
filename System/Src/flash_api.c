
#include "flash_api.h"
#include "logger.h"
#include "target.h"

//#define CNFG_DEBUG_PRINT_ON_SUCCESS

#define FLASH_PAGE_SIZE 16*1024

static const char* flash_error_type_text[] = 
{
  [FLASH_SR_EOP_Pos]     = "End of Operation",
  [FLASH_SR_SOP_Pos]     = "Operation Error",
  [FLASH_SR_WRPERR_Pos]  = "Write Protection Error",
  [FLASH_SR_PGAERR_Pos]  = "Programming Alignment Error",
  [FLASH_SR_PGPERR_Pos]  = "Programming Parallelism Error",
  [FLASH_SR_PGSERR_Pos]  = "Programming Sequence Error",
  [FLASH_SR_BSY_Pos]     = "Busy"
};

#define FLASH_FLAG_ALL_ERRORS \
  ( FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | \
    FLASH_FLAG_PGSERR | FLASH_FLAG_BSY )

static volatile uint8_t Flash_IsLocked = false;

#define CHECK_FLASH_LOCK() \
  if (Flash_IsLocked) \
  { \
    HAL_FLASH_Lock(); \
    return FLASH_LOCKED; \
  }

void Flash_SetLock(uint8_t isLocked)
{
  Flash_IsLocked = isLocked;
}

void Flash_ErrorDetailGet(uint32_t error_code)
{
    uint8_t index = 0;
    while(error_code != 0)
    {
      if(error_code & 1)
      {
        switch(index)
        {
          case FLASH_SR_EOP_Pos://0
          case FLASH_SR_SOP_Pos://1
          case FLASH_SR_WRPERR_Pos://4
          case FLASH_SR_PGAERR_Pos://5
          case FLASH_SR_PGPERR_Pos://6
          case FLASH_SR_PGSERR_Pos://7
          case FLASH_SR_BSY_Pos://16
            LOG(FLSH, ERROR,"Flash Error[%d] %s", index, flash_error_type_text[index]);
            break;
          default:
            LOG(FLSH, ERROR,"Flash Error[%d] Reserved,must be kept at reset value",index);
            break;
        }
      }
      error_code = error_code >> 1;
      index++;
    }
}

// Flash_Error_e Flash_WriteChunk(uint32_t address, chunk_t data)
// {
//   HAL_StatusTypeDef ret = HAL_OK;
//   uint32_t *pData = (uint32_t *)&data;
//   uint32_t *pFlashData = (uint32_t *)address;

//   CHECK_FLASH_LOCK();

//   if (address % sizeof(chunk_t))
//   {
//     LOG(FLSH, ERROR, "Misaligned adddress 0x%08X, data 0x%08X%08X, in flash (0x%08X%08X) code 0x%08X", address, pData[1], pData[0], pFlashData[1], pFlashData[0], HAL_FLASH_GetError());

//     return FLASH_BAD_ALIGNMENT_ERROR;
//   }

//   (void)pData;
//   (void)pFlashData;
//   HAL_FLASH_Unlock();

//   __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

  // HW_DEBUG_FLASH_GPIO_1(GPIO_PIN_SET);

// #if defined(STM32L072xx)
//   ret = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, data);
// #elif defined(STM32L452xx) || defined(STM32L476xx)
//   ret = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, address, data);
// #else
//   #error need appropriate chunk write function for this platform
// #endif

  // HW_DEBUG_FLASH_GPIO_1(GPIO_PIN_RESET);

//   HAL_FLASH_Lock();

//   if (ret != HAL_OK)
//   {
//     uint32_t error_code = HAL_FLASH_GetError();
//     LOG(FLSH, ERROR, "Failed to write to addr 0x%08X, data 0x%08X%08X, in flash (0x%08X%08X) code 0x%08X, ret %d", address, pData[1], pData[0], pFlashData[1], pFlashData[0], error_code, ret);
//     Flash_ErrorDetailGet(error_code);
//     return FLASH_ERROR;
//   }
// #ifdef CNFG_DEBUG_PRINT_ON_SUCCESS
//   else
//   {
//     LOG(FLSH, DEBUG, "Succeeded in write to addr 0x%08X, data 0x%08X%08X, in flash (0x%08X%08X) code 0x%08X, ret %d", address, pData[1], pData[0], pFlashData[1], pFlashData[0], HAL_FLASH_GetError(), ret);
//   }
// #endif

//   return (ret == HAL_OK) ? FLASH_NO_ERROR : FLASH_ERROR;
// }


Flash_Error_e Flash_WriteBytes(uint32_t address, uint8_t *pBytes, uint16_t numOfBytes)
{
  //Flash_Error_e ret = FLASH_NO_ERROR;
  HAL_StatusTypeDef ret = HAL_OK;
  uint16_t ctr = 0;

  CHECK_FLASH_LOCK();

  HAL_FLASH_Unlock();

  while ((ret == HAL_OK) && (ctr++ < numOfBytes))
  {
    CHECK_FLASH_LOCK();
    //ret = Flash_WriteChunk(address, *chunks);
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

    // HW_DEBUG_FLASH_GPIO_1(GPIO_PIN_SET);

    ret = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, address, *pBytes);
    address += sizeof(uint8_t);
    pBytes++;

    // HW_DEBUG_FLASH_GPIO_1(GPIO_PIN_RESET);
  }

  HAL_FLASH_Lock();

  if (ret != HAL_OK)
  {
    LOG(FLSH, ERROR, "Failed to write to addr 0x%08X, code 0x%08X, ret %d", address, HAL_FLASH_GetError(), ret);

    return FLASH_ERROR;
  }
#ifdef CNFG_DEBUG_PRINT_ON_SUCCESS
  else
  {
    LOG(FLSH, DEBUG, "Succeeded in write to addr 0x%08X, code 0x%08X, ret %d", address, HAL_FLASH_GetError(), ret);
  }
#endif

  //return ret;
  return (ret == HAL_OK) ? FLASH_NO_ERROR : FLASH_ERROR;
}


// Sector 0 0x0800 0000 - 0x0800 3FFF 16 Kbytes
// Sector 1 0x0800 4000 - 0x0800 7FFF 16 Kbytes
Flash_Error_e Flash_EraseSector(uint32_t sector_id)
{
  uint32_t error = 0;

  CHECK_FLASH_LOCK();

  // // Needs to be page aligned
  // if (sector_id != 0 && sector_id != 1)
  // {
  //   LOG(FLSH, ERROR, "Invalid sector ID attempted for erase!");

  //   return FLASH_BAD_ALIGNMENT_ERROR;
  // }

  FLASH_EraseInitTypeDef eraseType =
  {
    .TypeErase = FLASH_TYPEERASE_SECTORS,
    .Banks = FLASH_BANK_1,
    .Sector = sector_id,
    .NbSectors = 1,
    .VoltageRange = FLASH_VOLTAGE_RANGE_3
  };

  LOG(FLSH, INFO, "Erasing flash sector %d", sector_id);

  HAL_StatusTypeDef ret;
  HAL_FLASH_Unlock();

  // HW_DEBUG_FLASH_GPIO_1(GPIO_PIN_SET);

  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
  // ret = HAL_FLASHEx_Erase_LockCheck(&eraseType, &error, &Flash_IsLocked);
  ret = HAL_FLASHEx_Erase(&eraseType, &error);

  // HW_DEBUG_FLASH_GPIO_1(GPIO_PIN_RESET);

  HAL_FLASH_Lock();

  if (ret != HAL_OK)
  {
    LOG(FLSH, ERROR, "Failed to erase to sector %d, code 0x%08X", sector_id, HAL_FLASH_GetError());

    return FLASH_ERROR;
  }
#ifdef CNFG_DEBUG_PRINT_ON_SUCCESS
  else
  {
    LOG(FLSH, DEBUG, "Succeeded to erase to sector %d, code 0x%08X", sector_id, HAL_FLASH_GetError());
  }
#endif

  return (ret) ? FLASH_ERROR : FLASH_NO_ERROR;
}

void Flash_Init(void)
{
  
}
