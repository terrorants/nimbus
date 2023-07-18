#ifndef EVENTS_H
#define EVENTS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Audio Playback, Button handling, OLED Display, USB CDC
 */

typedef enum
{
  EVT_USB_CDC_RX			= 0,
  EVT_USB_CDC_TX_FLUSH      = 1,
} event_idx_e;

//#define eventSet(e)         do { eventMask |= (1 << e); } while (0)
//#define eventClear(e)       do { eventMask &= ~(1 << e); } while (0)
//#define eventCheck(e)       ((eventMask & (1 << e)) != 0)

//extern uint32_t eventMask;

void eventSet(event_idx_e eventIdx);
void eventClear(event_idx_e eventIdx);
bool eventCheck(event_idx_e eventIdx);

#endif // EVENTS_H
