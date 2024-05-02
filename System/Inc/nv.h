#ifndef __NV_H__
#define __NV_H__

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
  NV_AREA_0,
  NV_AREA_1,
  NV_AREA_MAX
} nv_area_e;

typedef enum
{
  NV_ID_LOGGER_LEVELS = 0x0001,
  NV_ID_INVALID = 0xFFFF,
  NV_ID_MAX
} nv_id_e;

void NV_Init(void);
void NV_Reset(void);
nv_area_e NV_SwitchArea(void);
bool NV_Read(uint16_t id, uint8_t *data, uint16_t *sz);
bool NV_Write(uint16_t id, uint8_t *data, uint16_t sz);

#endif /* __NV_H__ */