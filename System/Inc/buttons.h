#ifndef BUTTONS_H
#define BUTTONS_H

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

typedef enum
{
  BUTTON_ID_ENTER,
  BUTTON_ID_CANCEL,
  BUTTON_ID_UP,
  BUTTON_ID_RIGHT,
  BUTTON_ID_DOWN,
  BUTTON_ID_LEFT,
  BUTTON_ID_MAX
} button_id_e;

void buttons_init(void);
void buttons_interrupt_handler(button_id_e id);

#endif // BUTTONS_H