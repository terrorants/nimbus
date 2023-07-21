#include "tmr.h"
#include "target.h"

uint32_t tmrBaseMs = 0;

static tmr_entry_s tmrHead = {0};

void tmrTickHandler(void)
{
  tmr_entry_s *tmrPrev = (tmr_entry_s *)&tmrHead;
  tmr_entry_s *tmrCurr;

  tmrBaseMs++;

  while ((tmrCurr = tmrPrev->next) != NULL)
  {
    if (!(--tmrCurr->ms) && ((!tmrCurr->callback) || ((tmrCurr->callback) && ((tmrCurr->ms = tmrCurr->callback(tmrCurr->arg)) == 0))))
    {
      // Delete this Timer
      tmrPrev->next = tmrCurr->next;
    }
    else
    {
      // Previous Timer now gets Current Timer
      tmrPrev = tmrCurr;
    }
  }
}

void tmrAdd(tmr_entry_s *pEntry)
{
  ENTER_CRIT_SECTION;
  // Ensure that the timer in question is not already in the list, to prevent our 'next' pointers
  // from forming a loop.
  // Add new timer to end of list: Makes it safe to add a new timer from within in a timer callback function which will be deleted.
  tmr_entry_s *tmrCurr = (tmr_entry_s *)&tmrHead;
  while (tmrCurr->next != NULL)
  {
    if (tmrCurr->next == pEntry)
    {
      // This entry is already in the list, exit
      EXIT_CRIT_SECTION;
      return;
    }
    tmrCurr = tmrCurr->next;
  }  
  tmrCurr->next = pEntry;
  pEntry->next = NULL;
  EXIT_CRIT_SECTION;
}

void tmrDelete(tmr_entry_s *pEntry)
{
  ENTER_CRIT_SECTION;
  tmr_entry_s *tmrPrev = (tmr_entry_s *)&tmrHead;
  tmr_entry_s *tmrCurr;
  while ((tmrCurr = tmrPrev->next) != NULL)
  {
    if (tmrCurr == pEntry)
    {
      // Delete this Timer
      tmrPrev->next = tmrCurr->next;
      break;
    }
    // Previous Timer now gets Current Timer
    tmrPrev = tmrCurr;
  }
  EXIT_CRIT_SECTION;
}
