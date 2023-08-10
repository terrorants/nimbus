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
#include "testimg.h"

TK_SHELL_METHOD(disp, init);

TK_SHELL_METHOD(disp, init)
{
  int i = 0;
  int stage;

  if (argc != 1)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  stage = atoi(argv[i]);

  switch (stage)
  {
  case 0:
    PRINTF("Unselecting SSD1351\n");
    SSD1351_Unselect();
    // HAL_Delay(200);
    break;

  case 1:
    PRINTF("Initializing SSD1351\n");
    SSD1351_Init();
    // HAL_Delay(300);
    break;

  case 2:
    PRINTF("Drawing image\n");
    SSD1351_DrawImage(0, 0, 128, 128, (const uint16_t*)test_img_128x128);    
    break;

  default:
    break;
  }

  PRINTF("> disp:ok\n");
  return 0;
}

TK_SHELL_VERBS(disp) =
{
    TK_SHELL_VERB(disp, init, "initialize display"),
    { "", NULL, "" }
};
