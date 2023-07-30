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
#include "tk_shell_sd.h"
#include "ff.h"
#include "stm32f4xx.h"
#include "fatfs.h"
#include "usb_device.h"
// #include "usbd_cdc_msc.h"

TK_SHELL_METHOD(sd, test);

TK_SHELL_METHOD(sd, test)
{
  int i = 0;
  uint32_t on;

  if (argc != 1)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  //some variables for FatFs
  // FATFS FatFs;     //Fatfs handle
  // FIL fil;         //File handle
  // FRESULT fres; //Result after operations

  on = atoi(argv[i++]);
  //Open the file system
  //fres = f_mount(&FatFs, "", 1); //1=mount now
  //if (fres != FR_OK)
  // {
  //   PRINTF("f_mount error (%d)\r\n", fres);
  // }
  usb_device_deinit();
  HAL_Delay(3000);

  // USBD_MscEnable(!!on);

  usb_device_init();

  HAL_Delay(3000);

  MX_FATFS_Init();

    // port = *(argv[i++]);
    // pin = atoi(argv[i++]);
    // state = atoi(argv[i]);

    // HAL_GPIO_WritePin(getPortFromChar(port), 1 << pin, state);

    // PRINTF("> gpio:ok %d\n", HAL_GPIO_ReadPin(getPortFromChar(port), 1 << pin));
    return 0;
}

TK_SHELL_VERBS(sd) =
{
    TK_SHELL_VERB(sd, test, "SD test command"),
    { "", NULL, "" }
};
