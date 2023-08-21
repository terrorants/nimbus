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
#include "ssd1351.h"

static char path[128];

TK_SHELL_METHOD(sd, usb)
{
  // int i = 0;
  // uint32_t on;

  if (argc != 0)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  //some variables for FatFs
  // FATFS FatFs;     //Fatfs handle
  // FIL fil;         //File handle
  // FRESULT fres; //Result after operations

  // on = atoi(argv[i++]);
  //Open the file system
  //fres = f_mount(&FatFs, "", 1); //1=mount now
  //if (fres != FR_OK)
  // {
  //   PRINTF("f_mount error (%d)\r\n", fres);
  // }
  usb_device_deinit();
  HAL_Delay(3000);

  usb_device_enable_msc(true);

  usb_device_init();

  HAL_Delay(3000);

  // MX_FATFS_Init();

    // port = *(argv[i++]);
    // pin = atoi(argv[i++]);
    // state = atoi(argv[i]);

    // HAL_GPIO_WritePin(getPortFromChar(port), 1 << pin, state);

  PRINTF("> sd:ok\n");
  return 0;
}

TK_SHELL_METHOD(sd, ls)
{
  FRESULT res;
  DIR dir;

  res = f_opendir(&dir, path);

  if (res != FR_OK)
  {
    PRINTF("> sd:fail %d\n", res);
    return 0;
  }

  while (1)
  {
    FILINFO fno;

    res = f_readdir(&dir, &fno);

    if (res != FR_OK)
    {
      PRINTF("> sd:fail %d\n", res);
      return 0;
    }

    if (fno.fname[0] == 0)
    {
      break;
    }

    PRINTF("%c%c%c%c%c %10d %04d-%02d-%02d %02d:%02d:%02d %s\n",
          ((fno.fattrib & AM_DIR) ? 'D' : '-'),
          ((fno.fattrib & AM_RDO) ? 'R' : '-'),
          ((fno.fattrib & AM_SYS) ? 'S' : '-'),
          ((fno.fattrib & AM_HID) ? 'H' : '-'),
          ((fno.fattrib & AM_ARC) ? 'A' : '-'),
          (int)fno.fsize,
          (fno.fdate >> 9 & 0x7F) + 1980,
          (fno.fdate >> 5 & 0xF),
          (fno.fdate & 0x1F),
          (fno.ftime >> 11 & 0x1F),
          (fno.ftime >> 5 & 0x3F),
          (fno.ftime & 0x1F),
          fno.fname);
  }

  PRINTF("> sd:ok\n");
  f_closedir(&dir);

  return 0;
}

TK_SHELL_METHOD(sd, pwd)
{
  PRINTF("> sd:ok %s/\n", path);

  return 0;
}

TK_SHELL_METHOD(sd, cd)
{
  int i = 0;
  FRESULT res;
  DIR dir;

  if (argc != 1)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  res = f_opendir(&dir, argv[i]);

  if (res != FR_OK)
  {
    PRINTF("> sd:fail %d\n", res);
  }
  else
  {
    strncpy(path, argv[i], sizeof(path));
    PRINTF("> sd:ok %s/\n", path);
    f_closedir(&dir);
  }

  return 0;
}

TK_SHELL_VERBS(sd) =
{
    TK_SHELL_VERB(sd, usb, "SD mount to USB"),
    TK_SHELL_VERB(sd, ls, "list files"),
    TK_SHELL_VERB(sd, pwd, "Print working directory"),
    TK_SHELL_VERB(sd, cd, "Change directory"),
    { "", NULL, "" }
};
