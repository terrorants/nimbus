#include "buttons.h"
#include "main.h"
#include "stm32f4xx.h"
#include "tmr.h"

#define BTN_ENTRY(name) [BUTTON_ID_##name] = { BTN_##name##_GPIO_Port, BTN_##name##_Pin, BUTTON_STATE_idle, false }
#define BTN_DEBOUNCE_MS (20)

typedef enum
{
  BUTTON_STATE_idle,
  BUTTON_STATE_debounce_press,
  BUTTON_STATE_debounce_release
} button_state_e;

typedef struct
{
  GPIO_TypeDef        *port;
  uint16_t            pin;
  button_state_e      state;
  bool                pressed;
} button_config_s;

//typedef enum
//{
//  BUTTON_EVENT_idle,
//  BUTTON_EVENT_debounce,
//  BUTTON_EVENT_press,
//  BUTTON_EVENT_press_release,
//  BUTTON_EVENT_long_press,
//  BUTTON_EVENT_long_press_release,
//  BUTTON_EVENT_vlong_press,
//  BUTTON_EVENT_vlong_press_release
//} button_event_e;
//
//static const uint32_t buttonTimerThresholds[] =
//{
//  [BUTTON_EVENT_idle] = 0,
//  [BUTTON_EVENT_debounce] = 20,
//  [BUTTON_EVENT_press] = ,
//  [BUTTON_EVENT_press_release] = ,
//  [BUTTON_EVENT_long_press] = 800,
//  [BUTTON_EVENT_long_press_release] = ,
//  [BUTTON_EVENT_vlong_press] = 3000,
//  [BUTTON_EVENT_vlong_press_release] = ,
//};
static tmr_entry_s btnTimer[BUTTON_ID_MAX];

static button_config_s buttonConfigLUT[] =
{
  BTN_ENTRY(ENTER),
  BTN_ENTRY(CANCEL),
  BTN_ENTRY(UP),
  BTN_ENTRY(RIGHT),
  BTN_ENTRY(DOWN),
  BTN_ENTRY(LEFT),
  [BUTTON_ID_MAX] = { NULL, 0, BUTTON_STATE_idle, false }
};

static uint32_t buttons_timeout_handler(void *arg)
{
  button_id_e id = (button_id_e)arg;
  GPIO_PinState state = HAL_GPIO_ReadPin(buttonConfigLUT[id].port, buttonConfigLUT[id].pin);

  if (state == GPIO_PIN_SET && buttonConfigLUT[id].state == BUTTON_STATE_debounce_press)
  {
    buttonConfigLUT[id].pressed = true;
    // TODO: send event
  }
  else if (state == GPIO_PIN_RESET && buttonConfigLUT[id].state == BUTTON_STATE_debounce_release)
  {
    buttonConfigLUT[id].pressed = false;
    // TODO: send event
  }

  buttonConfigLUT[id].state = BUTTON_STATE_idle;

  return 0;
}

void buttons_init(void)
{
  
}

bool buttons_is_pressed(button_id_e id)
{
  return buttonConfigLUT[id].pressed;
}

void buttons_interrupt_handler(button_id_e id)
{
  GPIO_PinState state = HAL_GPIO_ReadPin(buttonConfigLUT[id].port, buttonConfigLUT[id].pin);

  if (state == GPIO_PIN_SET && buttonConfigLUT[id].pressed == false)
  {
    buttonConfigLUT[id].state = BUTTON_STATE_debounce_press;
    btnTimer[id].callback = buttons_timeout_handler;
    btnTimer[id].arg = (void *)id;
    btnTimer[id].ms = BTN_DEBOUNCE_MS;
    tmrAdd(&btnTimer[id]);
  }
  else if (state == GPIO_PIN_RESET && buttonConfigLUT[id].pressed == true)
  {
    buttonConfigLUT[id].state = BUTTON_STATE_debounce_release;
    btnTimer[id].callback = buttons_timeout_handler;
    btnTimer[id].arg = (void *)id;
    btnTimer[id].ms = BTN_DEBOUNCE_MS;
    tmrAdd(&btnTimer[id]);
  }
  else
  {
    // cancel all debouncing
    buttonConfigLUT[id].state = BUTTON_STATE_idle;
  }
}
