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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define PSB2_Pin GPIO_PIN_0
#define PSB2_GPIO_Port GPIOC
#define PSB1_Pin GPIO_PIN_1
#define PSB1_GPIO_Port GPIOC
#define BRK2_Pin GPIO_PIN_2
#define BRK2_GPIO_Port GPIOC
#define BATT_Pin GPIO_PIN_3
#define BATT_GPIO_Port GPIOC
#define DIRECTION3_Pin GPIO_PIN_0
#define DIRECTION3_GPIO_Port GPIOA
#define DIRECTION2_Pin GPIO_PIN_1
#define DIRECTION2_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define DIRECTION1_Pin GPIO_PIN_4
#define DIRECTION1_GPIO_Port GPIOA
#define DIRECTION6_Pin GPIO_PIN_5
#define DIRECTION6_GPIO_Port GPIOA
#define DIRECTION5_Pin GPIO_PIN_6
#define DIRECTION5_GPIO_Port GPIOA
#define PSB3_Pin GPIO_PIN_4
#define PSB3_GPIO_Port GPIOC
#define BRK1_Pin GPIO_PIN_0
#define BRK1_GPIO_Port GPIOB
#define PSB5_Pin GPIO_PIN_1
#define PSB5_GPIO_Port GPIOB
#define BRK5_Pin GPIO_PIN_2
#define BRK5_GPIO_Port GPIOB
#define pwm6_Pin GPIO_PIN_10
#define pwm6_GPIO_Port GPIOB
#define PSB6_Pin GPIO_PIN_12
#define PSB6_GPIO_Port GPIOB
#define BRK3_Pin GPIO_PIN_13
#define BRK3_GPIO_Port GPIOB
#define PSB4_Pin GPIO_PIN_14
#define PSB4_GPIO_Port GPIOB
#define BRK4_Pin GPIO_PIN_15
#define BRK4_GPIO_Port GPIOB
#define pwm1_Pin GPIO_PIN_8
#define pwm1_GPIO_Port GPIOA
#define pwm2_Pin GPIO_PIN_9
#define pwm2_GPIO_Port GPIOA
#define pwm3_Pin GPIO_PIN_10
#define pwm3_GPIO_Port GPIOA
#define BRK6_Pin GPIO_PIN_11
#define BRK6_GPIO_Port GPIOA
#define PSB6A12_Pin GPIO_PIN_12
#define PSB6A12_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOA
#define DIRECTION4_Pin GPIO_PIN_2
#define DIRECTION4_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define pwm4_Pin GPIO_PIN_8
#define pwm4_GPIO_Port GPIOB
#define pwm5_Pin GPIO_PIN_9
#define pwm5_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
