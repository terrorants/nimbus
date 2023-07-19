/*
 * events.c
 *
 *  Created on: Jul 18, 2023
 *      Author: terence_kim
 */
#include "events.h"

static uint32_t evtMask;

void eventSet(event_idx_e eventIdx)
{
  evtMask |= (1UL << eventIdx);
}

void eventClear(event_idx_e eventIdx)
{
  evtMask &= ~(1UL << eventIdx);
}

bool eventIsSet(event_idx_e eventIdx)
{
  return (evtMask & (1UL << eventIdx)) != 0;
}
