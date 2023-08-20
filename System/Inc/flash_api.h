
#ifndef FLASH_API_H
#define FLASH_API_H

#include <stdint.h>

/*
From the STM32L452RE reference manual section 3.3.7:
It is only possible to program double word (2 x 32-bit data).
 Any attempt to write byte or half-word will set SIZERR flag in the FLASH_SR register.
 Any attempt to write a double word which is not aligned with a double word address will set PGAERR flag in the FLASH_SR register.
*/

typedef enum {
  FLASH_NO_ERROR,
  // TODO
  FLASH_BAD_ALIGNMENT_ERROR,
  FLASH_ERROR,
  FLASH_LOCKED
} Flash_Error_e;

void Flash_Init(void);
// Flash_Error_e Flash_WriteChunk(uint32_t address, chunk_t data);
Flash_Error_e Flash_WriteBytes(uint32_t address, uint8_t *pBytes, uint16_t numOfBytes);
Flash_Error_e Flash_EraseSector(uint32_t sector_id);
void Flash_SetLock(uint8_t isLocked);

#endif // FLASH_API_H

