/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_ENTER_Pin GPIO_PIN_0
#define BTN_ENTER_GPIO_Port GPIOC
#define USER_LED_Pin GPIO_PIN_1
#define USER_LED_GPIO_Port GPIOC
#define BTN_UP_Pin GPIO_PIN_2
#define BTN_UP_GPIO_Port GPIOC
#define BTN_RIGHT_Pin GPIO_PIN_3
#define BTN_RIGHT_GPIO_Port GPIOC
#define BTN_DOWN_Pin GPIO_PIN_4
#define BTN_DOWN_GPIO_Port GPIOC
#define BTN_LEFT_Pin GPIO_PIN_5
#define BTN_LEFT_GPIO_Port GPIOC
#define SPARE_GPIO5_Pin GPIO_PIN_7
#define SPARE_GPIO5_GPIO_Port GPIOC
#define BTN_CANCEL_Pin GPIO_PIN_10
#define BTN_CANCEL_GPIO_Port GPIOA
#define SPI1_DC_Pin GPIO_PIN_3
#define SPI1_DC_GPIO_Port GPIOB
#define SSD1351_RST_Pin GPIO_PIN_4
#define SSD1351_RST_GPIO_Port GPIOB
#define SSD1351_CS_Pin GPIO_PIN_5
#define SSD1351_CS_GPIO_Port GPIOB
#define SD_DETECT_Pin GPIO_PIN_8
#define SD_DETECT_GPIO_Port GPIOB
#define SPARE_GPIO4_Pin GPIO_PIN_9
#define SPARE_GPIO4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
