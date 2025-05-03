#include "delay.h"	

/*********************************MIAO_DELAY_FUNC********************************************/
/*
ms delay function

return 1 : delay not complete

return 0 : delay complete
*/

uint8_t delay_ms(uint16_t time, uint32_t* get_tick ) 
{  
	if((uwTick - *get_tick) < time) return 1;
	
	*get_tick = uwTick;	
	
	return 0;
}


// 初始化DWT（在main()早期调用）
void DWT_Init(void) 
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;  // enable trace unit启用跟踪单元
    DWT->CYCCNT = 0;                                // empty counter计数器
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;            // start counter启动计数器
}

// 微秒级延时（基于CPU周期计算）
void Delay_us(uint32_t us) 
{
    uint32_t start = DWT_GetCycles();
    uint32_t ticks = us * (SystemCoreClock / 1000000); // calculate CPU cycles计算CPU周期数
    while ((DWT_GetCycles() - start) < ticks);
}

// 微秒级计时器检查
uint8_t Timer_Check_us(uint32_t *last_cycles, uint32_t interval_us) 
{
    uint32_t current = DWT_GetCycles();
    if (*last_cycles == 0 || (current - *last_cycles) >= (interval_us * (SystemCoreClock / 1000000))) {
        *last_cycles = current;
        return 0;
    }
    return 1;
}


/*********************************MIAO_DELAY_FUNC********************************************/	

