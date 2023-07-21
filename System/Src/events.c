/*
 * events.c
 *
 *  Created on: Jul 18, 2023
 *      Author: terence_kim
 */
#include "events.h"
#include "target.h"

static uint32_t evtMask;

void eventSet(event_idx_e eventIdx)
{
  ENTER_CRIT_SECTION;
  evtMask |= (1UL << eventIdx);
  EXIT_CRIT_SECTION;
}

void eventClear(event_idx_e eventIdx)
{
  ENTER_CRIT_SECTION;
  evtMask &= ~(1UL << eventIdx);
  EXIT_CRIT_SECTION;
}

bool eventIsSet(event_idx_e eventIdx)
{
  bool ret;

  ENTER_CRIT_SECTION;
  ret = (evtMask & (1UL << eventIdx)) != 0;
  EXIT_CRIT_SECTION;

  return ret;
}
