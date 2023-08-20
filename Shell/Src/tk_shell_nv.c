/*
 * tk_shell_nv.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tk_shell_nv.h"
#include "stm32f4xx.h"
#include "target.h"
#include "nv.h"

TK_SHELL_METHOD(nv, read)
{
  uint32_t addr;
  int i = 0;

  if (argc != 1)
  {
      PRINTF("Invalid number of arguments!\n");
      return -1;
  }

  addr = strtol(argv[i++], NULL, 16);

  PRINTF("addr = 0x%08X\n", addr);

  PRINTF("> nv:ok 0x%08X\n", *((uint32_t *)addr));
  return 0;
}

TK_SHELL_METHOD(nv, reset)
{
  NV_Reset();

  PRINTF("> nv:ok\n");
  return 0;
}

TK_SHELL_METHOD(nv, swap)
{
  nv_area_e area = NV_SwitchArea();

  PRINTF("> nv:ok %d\n", area);
  return 0;
}

TK_SHELL_VERBS(nv) =
{
    TK_SHELL_VERB(nv, read, "Read NV"),
    TK_SHELL_VERB(nv, reset, "Reset NV"),
    TK_SHELL_VERB(nv, swap, "Switch Areas"),
    { "", NULL, "" }
};
