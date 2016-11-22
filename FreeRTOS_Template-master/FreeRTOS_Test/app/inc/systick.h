#ifndef __SYSTICK__H
#define __SYSTICK__H

void DelayUs(u32 i);
void DelayMs(u32 i);

void RCC_HSE_Configuration(void); //自定义系统时间（可以修改时钟）

#endif
