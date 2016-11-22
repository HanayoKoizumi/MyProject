#include "include.h"

/**
 * LED初始化
 */
void LED_Init()	  //端口初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;	//声明一个结构体变量，用来初始化GPIO

	SystemInit();	//系统时钟初始化

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); /* 开启GPIO时钟 */

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;	 //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	  //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); /* 初始化GPIO */	
}

/**
 * 流水灯
 */
void LED_FlowLight( void *LED_FlowLight )//流水灯
{
	uint8_t i;

	for(;;)
	{
		for(i=0;i<8;i++)   //从左到右
		{
			GPIO_Write(GPIOC,(uint16_t)~(0x01<<i));//给IO口写输入数据
			//DelayMs(200);
			vTaskDelay (200/portTICK_RATE_MS);
		}
	}
}
