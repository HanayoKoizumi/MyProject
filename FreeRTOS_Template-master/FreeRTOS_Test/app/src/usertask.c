#include "include.h"

/**
 * STM32系统和外设初始化
 */
void STM32_SystemPeripheralsInit()
{
	RCC_HSE_Configuration();
	LED_Init();
	PrintfInit();
}

/**
 * 创建任务并运行
 */
void FreeRTOS_CreatTask()
{

	xTaskCreate(LED_FlowLight,
				"LED_FlowLight",
				50,
				NULL,
				1,
				NULL);

	xTaskCreate(Printf,
				"Printf",
				50,
				NULL,
				1,
				NULL
				);
	
	vTaskStartScheduler();
}
