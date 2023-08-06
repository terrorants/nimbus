/*
 * tk_shell_sd.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tk_shell_i2c.h"
#include "stm32f4xx.h"
#include "i2c.h"
#include "tmr.h"

#define FT_I2C_TIMEOUT    250

TK_SHELL_METHOD(i2c, scan);

TK_SHELL_METHOD(i2c, scan)
{
  HAL_StatusTypeDef status;
  uint8_t data[1];
  uint8_t myaddrs[32];
  uint8_t addrs_count = 0;
  uint8_t i = 0;

  if (argc != 0)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  addrs_count = 0;

  for (int addr = 2; addr < 256; addr += 2)
  {
    status = HAL_I2C_Master_Transmit(&hi2c1, addr, data, I2C_MEMADD_SIZE_8BIT, FT_I2C_TIMEOUT);

    if (status == HAL_OK)
    {
      if (addrs_count == sizeof(myaddrs))
      {
        break;
      }
      myaddrs[addrs_count++] = addr;
    }
    tmrSwDelay_us(2000);
  }

  while (i < addrs_count)
  {
    PRINTF("0x%X (0x%X)\n",myaddrs[i],(myaddrs[i]/2));
    i++;
  }
  
  PRINTF("> i2c:ok\n");
  return 0;
}

TK_SHELL_VERBS(i2c) =
{
    TK_SHELL_VERB(i2c, scan, "Scan for I2C devices on the bus"),
    { "", NULL, "" }
};
