/*
 * tk_shell_log.c
 *
 *  Created on: May 1, 2024
 *      Author: terence_kim
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tk_shell_log.h"
#include "stm32f4xx.h"
#include "nv.h"

TK_SHELL_METHOD(log, set);
TK_SHELL_METHOD(log, get);

static logger_module_e getModuleFromStr(char *moduleStr)
{
  int i = 0;
  while (i < LOGGER_MODULE_MAX)
  {
    if (strcasecmp(moduleStr, logger_module_str[i]) == 0)
    {
      return i;
    }
    i++;
  }
  return LOGGER_MODULE_MAX;
}

static uint8_t getBitmaskFromStr(char *levelsStr)
{
  uint8_t bm_lvl = 0;

  if (strchr(levelsStr, 'e') != NULL)
  {
    bm_lvl |= (1 << LOGGER_LEVEL_ERROR);
  }

  if (strchr(levelsStr, 'w') != NULL)
  {
    bm_lvl |= (1 << LOGGER_LEVEL_WARNING);
  }

  if (strchr(levelsStr, 'i') != NULL)
  {
    bm_lvl |= (1 << LOGGER_LEVEL_INFO);
  }

  if (strchr(levelsStr, 'd') != NULL)
  {
    bm_lvl |= (1 << LOGGER_LEVEL_DEBUG);
  }

  if (strcmp(levelsStr, "--") == 0)
  {
    bm_lvl = 0;
  }

  return bm_lvl;
}

TK_SHELL_METHOD(log, set)
{
    logger_module_e module;
    uint8_t mask;
    int i = 0;

    if (argc != 2)
    {
        PRINTF("Invalid number of arguments!\n");
        return -1;
    }

    module = getModuleFromStr(argv[i++]);
    mask = getBitmaskFromStr(argv[i++]);

    if (module < LOGGER_MODULE_MAX)
    {
        loggerSetModuleLevels(module, mask);
    }
    else
    {
        PRINTF("> log:fail - invalid module\n");
        return -1;
    }

    PRINTF("> log:%s\n", NV_Write(NV_ID_LOGGER_LEVELS, logger_levels, sizeof(uint8_t) * LOGGER_MODULE_MAX) ? "ok" : "fail");
    return 0;
}

TK_SHELL_METHOD(log, get)
{
    int module = 0;

    while (module < LOGGER_MODULE_MAX)
    {
      PRINTF("%4s: ", logger_module_str[module]);

      if (logger_levels[module] & (1 << LOGGER_LEVEL_ERROR))
      {
        PRINTF("e");
      }
      else
      {
        PRINTF("-");
      }

      if (logger_levels[module] & (1 << LOGGER_LEVEL_WARNING))
      {
        PRINTF("w");
      }
      else
      {
        PRINTF("-");
      }

      if (logger_levels[module] & (1 << LOGGER_LEVEL_INFO))
      {
        PRINTF("i");
      }
      else
      {
        PRINTF("-");
      }

      if (logger_levels[module] & (1 << LOGGER_LEVEL_DEBUG))
      {
        PRINTF("d");
      }
      else
      {
        PRINTF("-");
      }

      PRINTF("\n");
      module++;
    }

    PRINTF("> log:ok\n");

    return 0;
}

TK_SHELL_VERBS(log) =
{
    TK_SHELL_VERB(log, set, "set log levels"),
    TK_SHELL_VERB(log, get, "get log levels"),
    { "", NULL, "" }
};
