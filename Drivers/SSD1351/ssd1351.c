/* vim: set ai et ts=4 sw=4: */
#include "stm32f4xx_hal.h"
#include "ssd1351.h"
#include "tmr.h"
#include "logger.h"

// command list is based on https://github.com/adafruit/Adafruit-SSD1351-library
static const uint8_t initRecipe[] = 
{
  0xFD, 1, 0x12,              // COMMANDLOCK
  0xFD, 1, 0xB1,              // COMMANDLOCK
  0xAE, 0,                    // DISPLAYOFF
  0xB3, 1, 0xF1,         // CLOCKDIV: 7:4 = Oscillator Frequency, 3:0 = CLK Div Ratio (A[3:0]+1 = 1..16)
  0xCA, 1, 0x7F,         // MUXRATIO: 127
  0xA0, 1, 0x74,         // SETREMAP
  0x15, 2, 0x00, 0x7F,   // SETCOLUMN
  0x75, 2, 0x00, 0x7F,   // SETROW
  0xA1, 1, 0x00,         // STARTLINE: 96 if display height == 96
  0xA2, 1, 0x00,         // DISPLAYOFFSET
  0xB5, 1, 0x00,         // SETGPIO
  0xAB, 1, 0x01,         // FUNCTIONSELECT
  0xB1, 1, 0x32,         // PRECHARGE
  0xBE, 1, 0x05,         // VCOMH
  0xA6, 0,               // NORMALDISPLAY (don't invert)
  0xC1, 3, 0xC8, 0x80, 0xC8, // CONTRASTABC
  0xC7, 1, 0x0F,         // CONTRASTMASTER
  0xB4, 3, 0xA0, 0xB5, 0x55, // SETVSL
  0xB6, 1, 0x01,         // PRECHARGE2
  0xAF, 0,               // DISPLAYON
  0x00
};

static bool displayOn;

static void SSD1351_Select()
{
  HAL_GPIO_WritePin(SSD1351_CS_GPIO_Port, SSD1351_CS_Pin, GPIO_PIN_RESET);
}

void SSD1351_Unselect()
{
  HAL_GPIO_WritePin(SSD1351_CS_GPIO_Port, SSD1351_CS_Pin, GPIO_PIN_SET);
}

static void SSD1351_Reset()
{
  HAL_GPIO_WritePin(SSD1351_RES_GPIO_Port, SSD1351_RES_Pin, GPIO_PIN_SET);
  tmrSwDelay_us(3);
  HAL_GPIO_WritePin(SSD1351_RES_GPIO_Port, SSD1351_RES_Pin, GPIO_PIN_RESET);
  tmrSwDelay_us(3);
  HAL_GPIO_WritePin(SSD1351_RES_GPIO_Port, SSD1351_RES_Pin, GPIO_PIN_SET);
  // HAL_Delay(300);
}

static void SSD1351_WriteCommand(uint8_t cmd) 
{
  LOG(OLED, DEBUG, "C: %02X", cmd);
  HAL_GPIO_WritePin(SSD1351_DC_GPIO_Port, SSD1351_DC_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&SSD1351_SPI_PORT, &cmd, sizeof(cmd), HAL_MAX_DELAY);
}

static void SSD1351_WriteData(uint8_t* buff, size_t buff_size)
{
  LOG(OLED, DEBUG, "D: [%d]", buff_size);
  HAL_GPIO_WritePin(SSD1351_DC_GPIO_Port, SSD1351_DC_Pin, GPIO_PIN_SET);

  // split data in small chunks because HAL can't send more then 64K at once
  while(buff_size > 0)
  {
    uint16_t chunk_size = buff_size > 32768 ? 32768 : buff_size;
    HAL_SPI_Transmit(&SSD1351_SPI_PORT, buff, chunk_size, HAL_MAX_DELAY);
    buff += chunk_size;
    buff_size -= chunk_size;
  }
}

static void SSD1351_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  // column address set
  SSD1351_WriteCommand(0x15); // SETCOLUMN
  {
    uint8_t data[] = { x0 & 0xFF, x1 & 0xFF };
    SSD1351_WriteData(data, sizeof(data));
  }

  // row address set
  SSD1351_WriteCommand(0x75); // SETROW
  {
    uint8_t data[] = { y0 & 0xFF, y1 & 0xFF };
    SSD1351_WriteData(data, sizeof(data));
  }

  // write to RAM
  SSD1351_WriteCommand(0x5C); // WRITERAM
}

static void SSD1351_FollowRecipe(const uint8_t *recipe)
{
  while (*recipe != 0)
  {
    SSD1351_WriteCommand(*recipe++);
    if (*recipe > 0)
    {
      SSD1351_WriteData(&recipe[1], *recipe);
      recipe += *recipe + 1; // +1 for length field
    }
    else
    {
      recipe++;
    }
  }
}

void SSD1351_Command(uint8_t cmd)
{
  SSD1351_Select();
  SSD1351_WriteData(&cmd, sizeof(cmd));
  SSD1351_Unselect();
}

void SSD1351_Init(void)
{
//  uint8_t *p = &initRecipe[0];

  // Turn on SPI1 clock before first command
  __HAL_SPI_ENABLE(&SSD1351_SPI_PORT);

  SSD1351_Select();

  SSD1351_Reset();

  SSD1351_FollowRecipe(initRecipe);

  SSD1351_Unselect();

  displayOn = true;
}

void SSD1351_DrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
  if((x >= SSD1351_WIDTH) || (y >= SSD1351_HEIGHT))
    return;

  SSD1351_Select();

  SSD1351_SetAddressWindow(x, y, x+1, y+1);
  uint8_t data[] = { color >> 8, color & 0xFF };
  SSD1351_WriteData(data, sizeof(data));

  SSD1351_Unselect();
}

static void SSD1351_WriteChar(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor)
{
  uint32_t i, b, j;

  SSD1351_SetAddressWindow(x, y, x+font.width-1, y+font.height-1);

  for (i = 0; i < font.height; i++)
  {
    b = font.data[(ch - 32) * font.height + i];
    for (j = 0; j < font.width; j++)
    {
      if ((b << j) & 0x8000)
      {
        uint8_t data[] = { color >> 8, color & 0xFF };
        SSD1351_WriteData(data, sizeof(data));
      }
      else
      {
        uint8_t data[] = { bgcolor >> 8, bgcolor & 0xFF };
        SSD1351_WriteData(data, sizeof(data));
      }
    }
  }
}

void SSD1351_WriteString(uint16_t x, uint16_t y, const char* str, FontDef font, uint16_t color, uint16_t bgcolor)
{
  SSD1351_Select();

  while (*str)
  {
    if (x + font.width >= SSD1351_WIDTH)
    {
      x = 0;
      y += font.height;
      if (y + font.height >= SSD1351_HEIGHT)
      {
        break;
      }

      if(*str == ' ')
      {
        // skip spaces in the beginning of the new line
        str++;
        continue;
      }
    }

    SSD1351_WriteChar(x, y, *str, font, color, bgcolor);
    x += font.width;
    str++;
  }

  SSD1351_Unselect();
}

void SSD1351_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
  // clipping
  if((x >= SSD1351_WIDTH) || (y >= SSD1351_HEIGHT)) return;
  if((x + w - 1) >= SSD1351_WIDTH) w = SSD1351_WIDTH - x;
  if((y + h - 1) >= SSD1351_HEIGHT) h = SSD1351_HEIGHT - y;

  SSD1351_Select();
  SSD1351_SetAddressWindow(x, y, x+w-1, y+h-1);

  uint8_t data[] = { color >> 8, color & 0xFF };
  HAL_GPIO_WritePin(SSD1351_DC_GPIO_Port, SSD1351_DC_Pin, GPIO_PIN_SET);
  for (y = h; y > 0; y--)
  {
    for (x = w; x > 0; x--)
    {
      HAL_SPI_Transmit(&SSD1351_SPI_PORT, data, sizeof(data), HAL_MAX_DELAY);
    }
  }

  SSD1351_Unselect();
}

void SSD1351_FillScreen(uint16_t color)
{
  SSD1351_FillRectangle(0, 0, SSD1351_WIDTH, SSD1351_HEIGHT, color);
}

void SSD1351_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data)
{
  if((x >= SSD1351_WIDTH) || (y >= SSD1351_HEIGHT)) return;
  if((x + w - 1) >= SSD1351_WIDTH) return;
  if((y + h - 1) >= SSD1351_HEIGHT) return;

  SSD1351_Select();
  SSD1351_SetAddressWindow(x, y, x+w-1, y+h-1);
  SSD1351_WriteData((uint8_t*)data, sizeof(uint16_t)*w*h);
  SSD1351_Unselect();
}

void SSD1351_InvertColors(bool invert)
{
  SSD1351_Select();
  SSD1351_WriteCommand(invert ? 0xA7 /* INVERTDISPLAY */ : 0xA6 /* NORMALDISPLAY */);
  SSD1351_Unselect();
}

void SSD1351_DisplayOn(bool on)
{
  SSD1351_Select();
  SSD1351_WriteCommand(on ? 0xAF : 0xAE);
  SSD1351_Unselect();

  displayOn = on;
}

bool SSD1351_IsDisplayOn(void)
{
  return displayOn;
}