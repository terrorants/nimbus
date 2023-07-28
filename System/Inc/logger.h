#ifndef LOGGER_H
#define LOGGER_H

#include <string.h>

typedef enum
{
  LOGGER_MODULE_APP,
  LOGGER_MODULE_USB,
  LOGGER_MODULE_LOG,
  LOGGER_MODULE_STOR,
  LOGGER_MODULE_BTN,
  LOGGER_MODULE_OLED,
  LOGGER_MODULE_MAX
} logger_module_e;

typedef enum
{
  LOGGER_LEVEL_ERROR,
  LOGGER_LEVEL_WARNING,
  LOGGER_LEVEL_INFO,
  LOGGER_LEVEL_DEBUG,
  LOGGER_LEVEL_MAX
} logger_level_e;

#define LOG(module, level, ...)   loggerPrint(LOGGER_MODULE_##module, LOGGER_LEVEL_##level, __VA_ARGS__)
#define PRINTF(...)               loggerPrintf(__VA_ARGS__)

void loggerInit(void);

void loggerPrint(logger_module_e module, logger_level_e lvl, const char *fmt, ...);
void loggerPrintf(const char* format, ...);

#endif // LOGGER_H
