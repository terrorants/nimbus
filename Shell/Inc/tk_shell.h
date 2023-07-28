/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef TK_SHELL_H
#define TK_SHELL_H

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "logger.h"

#define TK_SHELL_METHOD(c, verb)              int __tk_shell_ ## c ## _ ## verb(int __unused argc, char __unused **argv)
#define TK_SHELL_COMMAND(name, desc)          {#name, (tk_shell_command_verb_s *)__tk_shell_verbs_ ## name, desc}
#define TK_SHELL_VERBS(name)                  const tk_shell_command_verb_s __tk_shell_verbs_ ## name[]
#define TK_SHELL_VERB(c, name, desc)          {#name, __tk_shell_ ## c ## _ ## name, desc}

#define CMD_BUF_LEN 64
#define TK_SHELL_MAX_ARGS 10

typedef struct
{
  const char *name;
  int        (*func)(int argc, char **argv);
  const char *desc;
} tk_shell_command_verb_s;

typedef struct
{
  const char *name;
  tk_shell_command_verb_s *verbs;
  const char *desc;
} tk_shell_command_s;

void TkShellInit(void);
void TkShellService(void);

#endif /* TK_SHELL_H */

/* [] END OF FILE */
