/*
 * logger.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include "logger.h"
#include "drv_vcp.h"

const char *modStr[LOGGER_MODULE_MAX] =
{
  " APP",
  " USB",
  " LOG",
  "STOR",
  " BTN",
  "OLED",
};

const char levelChar[LOGGER_LEVEL_MAX] =
{
  'E',
  'W',
  'I',
  'D'
};

extern int xvsnprintf(char* __restrict b0, size_t b0len, const char* __restrict fmt0, va_list ap);
char dbg_output_buffer[250];
char tmr_output_buffer[40];

static void logger_vprintf(const char* format, va_list args)
{
  // format into a static buffer
  int result = xvsnprintf(dbg_output_buffer, sizeof(dbg_output_buffer), format, args);
  if (result > 0) {
      VCP_SendData((uint8_t *)dbg_output_buffer, result);
  }
}

static void logger_printf(const char* format, ...)
{
  va_list argp;
  va_start(argp, format);
  logger_vprintf(format, argp);
  va_end(argp);
}

void loggerInit(void)
{

}

void loggerPrint(logger_module_e module, logger_level_e lvl, const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  logger_printf("[%s] %c ", modStr[module], levelChar[lvl]);
  logger_vprintf(fmt, args);
  logger_printf("\n");
  va_end(args);
}

