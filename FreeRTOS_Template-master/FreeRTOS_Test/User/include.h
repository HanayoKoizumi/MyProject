#ifndef __INCLUDE__H
#define __INCLUDE__H

/**
 * FreeRTOS lib
 */
#include "FreeRTOS.h"

/**
 * stm32lib
 */
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"

/**
 * FreeRTOS API
 */
#include "usertask.h"

/**
 * 调用32标准库的底层任务
 */
#include "stdio.h"
#include "systick.h"
#include "led.h"
#include "printf.h"

#endif
