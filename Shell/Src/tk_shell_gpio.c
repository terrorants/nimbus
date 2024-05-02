/*
 * tk_shell_gpio.c
 *
 *  Created on: Jul 19, 2023
 *      Author: terence_kim
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tk_shell_gpio.h"
#include "stm32f4xx.h"

TK_SHELL_METHOD(gpio, set);
TK_SHELL_METHOD(gpio, config);
TK_SHELL_METHOD(gpio, get);

static GPIO_TypeDef* getPortFromChar(char c)
{
  switch (c)
  {
  case 'A':
    return GPIOA;
  case 'B':
    return GPIOB;
  case 'C':
    return GPIOC;

  case 'H':
  default:
    return GPIOH;
  }

  return NULL;
}

//static char getCharFromPort(GPIO_TypeDef *g)
//{
// if (g == GPIOA) return 'A';
// if (g == GPIOB) return 'B';
// if (g == GPIOC) return 'C';
// if (g == GPIOH) return 'H';
//
// return '\0';
//}

TK_SHELL_METHOD(gpio, set)
{
    uint32_t port, pin, state;
    int i = 0;

    if (argc != 3)
    {
        PRINTF("Invalid number of arguments!\n");
        return -1;
    }

    port = *(argv[i++]);
    pin = atoi(argv[i++]);
    state = atoi(argv[i]);

    HAL_GPIO_WritePin(getPortFromChar(port), 1 << pin, state);

    PRINTF("> gpio:ok %d\n", HAL_GPIO_ReadPin(getPortFromChar(port), 1 << pin));
    return 0;
}

// TK_SHELL_METHOD(gpio, config)
// {
//     uint32_t port, pin, mode;
//     int i = 0;

//     if (argc != 3)
//     {
//         PRINTF("Invalid number of arguments!\n");
//         return -1;
//     }

//     port = atoi(argv[i++]);
//     pin = atoi(argv[i++]);
//     mode = atoi(argv[i]);

// //    CY_SYS_PINS_SET_DRIVE_MODE(reg_lookup[port], pin, mode);

//     return 0;
// }

TK_SHELL_METHOD(gpio, get)
{
    uint32_t port, pin;
    int i = 0;

    if (argc != 2)
    {
        PRINTF("Invalid number of arguments!\n");
        return -1;
    }

    port = atoi(argv[i++]);
    pin = atoi(argv[i]);

    PRINTF("> gpio:ok %d\n", HAL_GPIO_ReadPin(getPortFromChar(port), 1 << pin));

    return 0;
}

TK_SHELL_VERBS(gpio) =
{
    TK_SHELL_VERB(gpio, set, "set GPIO state"),
    // TK_SHELL_VERB(gpio, config, "configure GPIO"),
    TK_SHELL_VERB(gpio, get, "get GPIO state"),
    { "", NULL, "" }
};
