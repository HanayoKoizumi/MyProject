#include "include.h"

/*******************************************************************************
* 函 数 名         : delay_us
* 函数功能		   : 延时函数，延时us
* 输    入         : i
* 输    出         : 无
*******************************************************************************/
void DelayUs(u32 i)
{
	u32 temp;
	SysTick->LOAD=9*i;		 //设置重装数值, 72MHZ时
	SysTick->CTRL=0X01;		 //使能，减到零是无动作，采用外部时钟源
	SysTick->VAL=0;		   	 //清零计数器
	do
	{
		temp=SysTick->CTRL;		   //读取当前倒计数值
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	 //等待时间到达
	SysTick->CTRL=0;	//关闭计数器
	SysTick->VAL=0;		//清空计数器
}

/*******************************************************************************
* 函 数 名         : delay_ms
* 函数功能		   : 延时函数，延时ms
* 输    入         : i
* 输    出         : 无
*******************************************************************************/
void DelayMs(u32 i)
{
	u32 temp;
	SysTick->LOAD=9000*i;	  //设置重装数值, 72MHZ时
	SysTick->CTRL=0X01;		//使能，减到零是无动作，采用外部时钟源
	SysTick->VAL=0;			//清零计数器
	do
	{
		temp=SysTick->CTRL;	   //读取当前倒计数值
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	//等待时间到达
	SysTick->CTRL=0;	//关闭计数器
	SysTick->VAL=0;		//清空计数器
}

/*******************************************************************************
* 函 数 名         : RCC_HSE_Configuration
* 函数功能		   : 自定义系统时钟，可以通过修改PLL时钟源和倍频系数实现时钟调整
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void RCC_HSE_Configuration() //自定义系统时间（可以修改时钟）
{
	RCC_DeInit(); //将外设RCC寄存器重设为缺省值
	RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE）
	if(RCC_WaitForHSEStartUp()==SUCCESS) //等待HSE起振
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK）
		RCC_PCLK1Config(RCC_HCLK_Div2);//设置低速AHB时钟（PCLK1）
		RCC_PCLK2Config(RCC_HCLK_Div1);//设置高速AHB时钟（PCLK2）
		RCC_PLLConfig(RCC_PLLSource_HSE_Div2,RCC_PLLMul_9);//设置PLL时钟源及倍频系数
		RCC_PLLCmd(ENABLE); //使能或者失能PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//设置系统时钟（SYSCLK）
		while(RCC_GetSYSCLKSource()!=0x08);//返回用作系统时钟的时钟源,0x08：PLL作为系统时钟
	}
}
