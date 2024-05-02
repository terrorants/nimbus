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

#define BMASK(x)             (1 << x)

#define LOGGER_LEVEL___F     0
#define LOGGER_LEVEL_E_F     BMASK(LOGGER_LEVEL_ERROR)
#define LOGGER_LEVEL_W_F     BMASK(LOGGER_LEVEL_WARNING)
#define LOGGER_LEVEL_I_F     BMASK(LOGGER_LEVEL_INFO)
#define LOGGER_LEVEL_D_F     BMASK(LOGGER_LEVEL_DEBUG)

// Specify 'E', 'W', 'I', 'D'. '_' will mean disable.
// Ex:  LOGGER_LEVEL_MASK(E, W, _, _) means ERROR and WARNING have been enabled. All other logs are disabled.
#define LOGGER_LEVEL_MASK(E, W, I, D) (LOGGER_LEVEL_ ## E ## _F | LOGGER_LEVEL_ ## W ## _F | LOGGER_LEVEL_ ## I ## _F | LOGGER_LEVEL_ ## D ## _F)

const char *logger_module_str[LOGGER_MODULE_MAX] =
{
  "APP",
  "FLSH",
  "USB",
  "LOG",
  "STOR",
  "BTN",
  "OLED",
};

static const char levelChar[LOGGER_LEVEL_MAX] =
{
  'E',
  'W',
  'I',
  'D'
};

uint8_t logger_levels[LOGGER_MODULE_MAX] =
{
  [LOGGER_MODULE_APP]  = LOGGER_LEVEL_MASK(E, W, I, D),
  [LOGGER_MODULE_FLSH] = LOGGER_LEVEL_MASK(E, W, I, _),
  [LOGGER_MODULE_USB]  = LOGGER_LEVEL_MASK(E, W, I, D),
  [LOGGER_MODULE_LOG]  = LOGGER_LEVEL_MASK(E, W, I, D),
  [LOGGER_MODULE_STOR] = LOGGER_LEVEL_MASK(E, W, I, D),
  [LOGGER_MODULE_BTN]  = LOGGER_LEVEL_MASK(E, W, I, D),
  [LOGGER_MODULE_OLED] = LOGGER_LEVEL_MASK(E, W, I, D),
};

extern int xvsnprintf(char* __restrict b0, size_t b0len, const char* __restrict fmt0, va_list ap);
char dbg_output_buffer[250];
char tmr_output_buffer[40];

static void logger_vprintf(const char* format, va_list args)
{
  // format into a static buffer
  int result = xvsnprintf(dbg_output_buffer, sizeof(dbg_output_buffer), format, args);
  if (result > 0) {
      VCP_SendData((char *)dbg_output_buffer, result);
  }
}

void loggerPrintf(const char* format, ...)
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

  if ((logger_levels[module] & BMASK(lvl)) != 0)
  {
    va_start(args, fmt);
    loggerPrintf("[%4s] %c ", logger_module_str[module], levelChar[lvl]);
    logger_vprintf(fmt, args);
    loggerPrintf("\n");
    va_end(args);
  }
}

void loggerSetModuleLevels(logger_module_e module, uint8_t bm_lvl)
{
  if (module < LOGGER_MODULE_MAX)
  {
    logger_levels[module] = bm_lvl;
  }
}
