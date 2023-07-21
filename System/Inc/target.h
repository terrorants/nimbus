#ifndef TARGET_H_
#define TARGET_H_

// Include Target Standard Libraries
#include <stddef.h>
#include <stdio.h>                                          // Include Standard I/O
#include <stdlib.h>                                         // Include Standard Lib
#include <stdbool.h>
#include <stdint.h>
#include <string.h>                                         // Include String
#include <ctype.h>                                          // Include CType

// NOTE: If you are using CMSIS, the registers can also be
// accessed through CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk
#define HALT_IF_DEBUGGING()                                 \
  do {                                                      \
    if (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) { \
      __asm("bkpt 1");                                      \
    }                                                       \
} while (0)

#define ENTER_CRIT_SECTION      \
    uint32_t primask = 0;\
    targetGetInterruptState(primask);\
    targetDisableInterrupts()\

#define EXIT_CRIT_SECTION     \
    targetRestoreInterruptState(primask)
    
//extern volatile uint32_t priMask;
// Map Target's NOP
#define targetNop()   __nop()

// Map Target Functions
#define targetDisableInterrupts()   __disable_irq()
#define targetEnableInterrupts()    __enable_irq()

#define targetReset()               do {\
    __disable_irq();\
    NVIC_SystemReset();\
  }while(0);  // This will cause a system reset and the software reset RCC_FLAG_SFTRST flag will be set.

#define targetAssert(x) \
  do { \
    if (!(x)) { \
      dbg_printf("ASSERT: %s (%d)\n", __FILE__, __LINE__); \
      HALT_IF_DEBUGGING(); \
    } \
  } while(0)

#define targetWFI()                    __wfi()
#define targetEnableIRQ(x)             NVIC_EnableIRQ(x)
#define targetDisableIRQ(x)            NVIC_EnableIRQ(x)
//#define trgGetIRQ(x)                 NVIC_GetIRQ(x)
#define targetClearPendingIRQ(x)       NVIC_ClearPendingIRQ(x)
#define targetGetInterruptState(x)      x = __get_PRIMASK()
#define targetRestoreInterruptState(x)  __set_PRIMASK(x)  // Restore previous interrupt state
#define targetEnableExceptions()       __set_PRIMASK(0)
#define targetTriggerHardFault()       do { static void (*f)(void); f(); } while(0)
#define ASSERT(x)                      do { if (!(x)) targetTriggerHardFault(); } while(0)

// Define target byte-order routines
#ifndef htons
#define htons(x) (((((uint16_t)(x) & 0x00FF)) << 8) | (((uint16_t)(x) & 0xFF00) >> 8))
#endif
#ifndef htonl
#define htonl(x) ((((uint32_t)(x))<<24) | ((((uint32_t)(x))&0x00FF0000l)>>8) | ((((uint32_t)(x))&0x0000FF00l)<<8) | (((uint32_t)(x))>>24))
#endif
#ifndef ntohs
#define ntohs(x) htons(x)
#endif
#ifndef ntohl
#define ntohl(x) htonl(x)
#endif
#ifndef ntohll
#define ntohll(x) ((((uint64_t)ntohl(x&0xFFFFFFFF)) << 32) + ntohl(x >> 32))
#endif

#endif


