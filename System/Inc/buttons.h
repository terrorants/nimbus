#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>

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
bool buttons_is_pressed(button_id_e id);
void buttons_interrupt_handler(button_id_e id);

#endif // BUTTONS_H
