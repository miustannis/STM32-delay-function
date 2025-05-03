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


// ��ʼ��DWT����main()���ڵ��ã�
void DWT_Init(void) 
{
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;  // enable trace unit���ø��ٵ�Ԫ
    DWT->CYCCNT = 0;                                // empty counter������
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;            // start counter����������
}

// ΢�뼶��ʱ������CPU���ڼ��㣩
void Delay_us(uint32_t us) 
{
    uint32_t start = DWT_GetCycles();
    uint32_t ticks = us * (SystemCoreClock / 1000000); // calculate CPU cycles����CPU������
    while ((DWT_GetCycles() - start) < ticks);
}

// ΢�뼶��ʱ�����
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

