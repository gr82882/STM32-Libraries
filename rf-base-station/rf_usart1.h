/**
 ******************************************************************************
 * @file	rf_usart1.h
 * @author	Hampus Sandberg
 * @version	0.1
 * @date	2013-05-10
 * @brief	Manage USART
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef RF_USART1_H_
#define RF_USART1_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "input-output/outstream.h"

/* Defines -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
OUT_Device RF_USART1;

/* Typedefs ------------------------------------------------------------------*/
/* Function prototypes -------------------------------------------------------*/
void RF_USART1_Init();

#endif /* RF_USART1_H_ */