#include <stdbool.h>
#include "stm32f4xx.h"
#include "oled_manager.h"
#include "ssd1351.h"
#include "testimg.h"
#include "logger.h"
#include "tmr.h"
#include "lvgl.h"
#include "logger.h"

#define BUFF_SIZE 128*10
#define SPLASH_SCREEN_TIMEOUT_MS  30000
#define LVGL_TIMEOUT_MS           5000

//Frame buffers
/*Static or global buffer(s). The second buffer is optional*/
static lv_color_t buf_1[BUFF_SIZE]; //TODO: Chose a buffer size. DISPLAY_WIDTH * 10 is one suggestion.
static lv_color_t buf_2[BUFF_SIZE];

typedef struct
{
  uint32_t displayOnTimestampMs;
  uint32_t prevHandlerTimestampMs;
} oled_manager_cb_s;

static oled_manager_cb_s oled;

static void lvgl_printf(int8_t level, const char *buf)
{
  // TODO: filter by level
  if (level >= LV_LOG_LEVEL_INFO)
  {
    loggerPrintf(buf);
  }
}

void my_flush_cb(lv_disp_t * disp, const lv_area_t * area, uint8_t *color_p)
{
  // void SSD1351_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)

  //Set the drawing region
  // set_draw_window(area->x1, area->y1, area->x2, area->y2);

  int height = area->y2 - area->y1 + 1;
  int width = area->x2 - area->x1 + 1;

  lv_color16_t *p_color16 = (lv_color16_t *)color_p;

  // (color_p->red << 11) | (color_p->green << 5) | (color_p->blue);

  LOG(OLED, INFO, "my_flush_cb: {%d, %d}, w:%d, h:%d, #%04X[%d] r(%d), g(%d), b(%d)", area->x1, area->y1, width, height, *((uint16_t *)p_color16), sizeof(lv_color16_t), p_color16->red, p_color16->green, p_color16->blue);

  // SSD1351_FillRectangle(area->x1, area->y1, width, height, color_full);

#if 0

  //We will do the SPI write manually here for speed
  // HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_SET);
  //CS low to begin data
  HAL_GPIO_WritePin(SSD1351_CS_GPIO_Port, SSD1351_CS_Pin, GPIO_PIN_RESET);

  //Write colour to each pixel
  for (int i = 0; i < width * height; i++) {
    // uint16_t color_full = (color_p->red << 11) | (color_p->green << 5) | (color_p->blue);
    // parallel_write(color_full);
    SSD1351_DrawPixel(i % width, i / width, *((uint16_t *)p_color16), false);

    p_color16++;
  }

  //Return CS to high
  HAL_GPIO_WritePin(SSD1351_CS_GPIO_Port, SSD1351_CS_Pin, GPIO_PIN_SET);
#else
  SSD1351_DrawRectangle(area->x1, area->y1, area->x2, area->y2, p_color16);
#endif

  /* IMPORTANT!!!
  * Inform the graphics library that you are ready with the flushing*/
  lv_disp_flush_ready(disp);
}

void OLED_Init(void)
{
  SSD1351_Init();

  LOG(OLED, INFO, "Displaying splash image...");

  // SSD1351_DrawImage(0, 0, 128, 128, (const uint16_t*)test_img_128x128);

  lv_log_register_print_cb(lvgl_printf);
  lv_init();

  lv_disp_t * disp = lv_disp_create(128, 128); /*Basic initialization with horizontal and vertical resolution in pixels*/
  lv_disp_set_flush_cb(disp, my_flush_cb); /*Set a flush callback to draw to the display*/
  lv_disp_set_draw_buffers(disp, buf_1, buf_2, sizeof(buf_1), LV_DISP_RENDER_MODE_PARTIAL); /*Set an initialized buffer*/

  // Change the active screen's background color
  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x003a57), LV_PART_MAIN);
  lv_obj_set_style_text_color(lv_scr_act(), lv_color_hex(0xffffff), LV_PART_MAIN);

  /*Create a spinner*/
  lv_obj_t * spinner = lv_spinner_create(lv_scr_act(), 1000, 60);
  lv_obj_set_size(spinner, 64, 64);
  lv_obj_align(spinner, LV_ALIGN_BOTTOM_MID, 0, 0);
}

void OLED_Service(void)
{
  if (SSD1351_IsDisplayOn() && tmrElapsedMs(oled.displayOnTimestampMs) > SPLASH_SCREEN_TIMEOUT_MS)
  {
    SSD1351_DisplayOn(false); // turn off image
  }


  if (tmrElapsedMs(oled.prevHandlerTimestampMs) >= LVGL_TIMEOUT_MS)
  {
    lv_timer_handler();
    oled.prevHandlerTimestampMs = tmrNow();
  }
}

void OLED_KickInactivityTimer(void)
{
  oled.displayOnTimestampMs = tmrNow();
}