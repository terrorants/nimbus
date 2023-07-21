#ifndef TMR_H
#define TMR_H

#include <stdint.h>

extern uint32_t tmrBaseMs;

#define tmrNow()              (tmrBaseMs)
#define tmrElapsedMs(then)    (tmrNow() - then)

typedef uint32_t (*tmr_callback_fp)(void *arg);

typedef struct tmr_entry
{
  struct tmr_entry  *next;
  uint32_t          ms;
  void              *arg;
  tmr_callback_fp   callback;
} tmr_entry_s;

void tmrTickHandler(void);
void tmrAdd(tmr_entry_s *pEntry);
void tmrDelete(tmr_entry_s *pEntry);

#endif // TMR_H
