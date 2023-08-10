/*
 * tk_shell_sys.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tk_shell_sys.h"
#include "stm32f4xx.h"
#include "target.h"

TK_SHELL_METHOD(sys, reset);

TK_SHELL_METHOD(sys, reset)
{
  targetReset();
  return 0;
}

TK_SHELL_VERBS(sys) =
{
    TK_SHELL_VERB(sys, reset, "Reset chip"),
    { "", NULL, "" }
};
