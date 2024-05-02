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

TK_SHELL_METHOD(log, set);
TK_SHELL_METHOD(log, get);

static logger_module_e getModuleFromStr(char *moduleStr)
{
  int i = 0;
  while (i < LOGGER_MODULE_MAX)
  {
    if (strcmpi(moduleStr, logger_module_str[i]) == 0)
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

    PRINTF("> log:ok\n");
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
      if (logger_levels[module] & (1 << LOGGER_LEVEL_WARNING))
      {
        PRINTF("w");
      }
      if (logger_levels[module] & (1 << LOGGER_LEVEL_INFO))
      {
        PRINTF("i");
      }
      if (logger_levels[module] & (1 << LOGGER_LEVEL_DEBUG))
      {
        PRINTF("d");
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
