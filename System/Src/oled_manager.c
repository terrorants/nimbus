#include <stdbool.h>
#include "oled_manager.h"
#include "ssd1351.h"
#include "testimg.h"
#include "logger.h"
#include "tmr.h"

#define SPLASH_SCREEN_TIMEOUT_MS  10000

typedef struct
{
  uint32_t displayOnTimestampMs;
} oled_manager_cb_s;

static oled_manager_cb_s oled;

void OLED_Init(void)
{
  SSD1351_Init();

  LOG(OLED, INFO, "Displaying splash image...");

  SSD1351_DrawImage(0, 0, 128, 128, (const uint16_t*)test_img_128x128);
}

void OLED_Service(void)
{
  if (SSD1351_IsDisplayOn() && tmrElapsedMs(oled.displayOnTimestampMs) > SPLASH_SCREEN_TIMEOUT_MS)
  {
    SSD1351_DisplayOn(false); // turn off image
  }
}

void OLED_KickInactivityTimer(void)
{
  oled.displayOnTimestampMs = tmrNow();
}