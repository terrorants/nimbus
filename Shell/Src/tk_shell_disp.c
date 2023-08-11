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
#include "oled_manager.h"

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
    PRINTF("Initializing SSD1351\n");
    SSD1351_Init();
    break;

  case 1:
    PRINTF("Drawing image\n");
    SSD1351_DrawImage(0, 0, 128, 128, (const uint16_t*)test_img_128x128);
    break;

  default:
    break;
  }

  PRINTF("> disp:ok\n");
  return 0;
}

TK_SHELL_METHOD(disp, cmd)
{
  int i = 0;
  uint8_t cmd;

  if (argc != 1)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  cmd = strtol(argv[i++], NULL, 16);

  SSD1351_Command(cmd);
  PRINTF("> disp:ok 0x%02X\n", cmd);

  return 0;
}

TK_SHELL_METHOD(disp, on)
{
  if (argc != 0)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  SSD1351_DisplayOn(true);
  OLED_KickInactivityTimer();

  PRINTF("> disp:ok\n");

  return 0;
}

TK_SHELL_METHOD(disp, off)
{
  if (argc != 0)
  {
    PRINTF("Invalid number of arguments!\n");
    return -1;
  }

  SSD1351_DisplayOn(false);

  PRINTF("> disp:ok\n");

  return 0;
}

TK_SHELL_VERBS(disp) =
{
  TK_SHELL_VERB(disp, init, "initialize display"),
  TK_SHELL_VERB(disp, on, "turn on display"),
  TK_SHELL_VERB(disp, off, "turn off display"),
  TK_SHELL_VERB(disp, cmd, "send command"),
  { "", NULL, "" }
};
