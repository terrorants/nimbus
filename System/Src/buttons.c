#include "buttons.h"
#include "main.h"
#include "stm32f4xx.h"

#define BTN_ENTRY(name) [BUTTON_ID_##name] = { BTN_##name##_GPIO_PORT, BTN_##name, BUTTON_STATE_unpressed }

typedef enum
{
  BUTTON_STATE_unpressed,
  BUTTON_STATE_debouncing,
  BUTTON_STATE_pressed
} button_state_e;

typedef struct
{
  GPIO_TypeDef    *port;
  uint16_t        pin;
  button_state_e  state;
} button_config_s;



typedef enum
{
  BUTTON_EVENT_idle,
  BUTTON_EVENT_debounce,
  BUTTON_EVENT_press,
  BUTTON_EVENT_press_release,
  BUTTON_EVENT_long_press,
  BUTTON_EVENT_long_press_release,
  BUTTON_EVENT_vlong_press,
  BUTTON_EVENT_vlong_press_release
} button_event_e;

static const uint32_t buttonTimerThresholds[] = 
{
  [BUTTON_EVENT_idle] = 0,
  [BUTTON_EVENT_debounce] = 20,
  [BUTTON_EVENT_press] = ,
  [BUTTON_EVENT_press_release] = ,
  [BUTTON_EVENT_long_press] = 800,
  [BUTTON_EVENT_long_press_release] = ,
  [BUTTON_EVENT_vlong_press] = 3000,
  [BUTTON_EVENT_vlong_press_release] = ,
};

static tmr_entry_s btnTimer[BUTTON_ID_MAX];

static button_config_s buttonConfigLUT[] =
{
  // BTN_ENTRY(ENTER),
  // BTN_ENTRY(CANCEL),
  BTN_ENTRY(UP),
  BTN_ENTRY(RIGHT),
  BTN_ENTRY(DOWN),
  BTN_ENTRY(LEFT),
  [BUTTON_ID_MAX] = { NULL, 0, BUTTON_STATE_unpressed }
};

static void buttons_debounce_timer_start(button_event_e event, uint32_t ms)
{

}

void buttons_init(void)
{
  
}

void buttons_interrupt_handler(button_id_e id)
{
  GPIO_PinState state = HAL_GPIO_ReadPin(buttonConfigLUT[id].port, buttonConfigLUT[id].pin);
}