#include "stc15f104e.h"

#include <string.h>
#include "public/inc/RS-232.h"
#include "public/inc/timer.h"
#include "public/inc/delay.h"  

unsigned int idata guiTimer1S = 4000;

sbit LED0 = P3 ^ 0;
sbit LED1 = P3 ^ 1;
sbit LED2 = P3 ^ 2;
sbit LED3 = P3 ^ 3;
sbit LED4 = P3 ^ 4;
sbit LED5 = P3 ^ 5;

void main(void) 
{
	P3M1 = 0x0;
	P3M0 = 0x0;
    
	EX1 = 1;
	IT1 = 1;

	timer0_initial();

	LED0 = 0;
    LED1 = 0;
    LED2 = 1;
    LED3 = 1;

    LED4 = 0;
    LED5 = 1;  

	while(1) 
	{ 
		LED2 = ~LED2;

		delay_ms(500);	
	} //end of while
}

void isr_int0() interrupt 0
{
    guiTimer1S = 30000; 
}

void isr_int1() interrupt 2
{
    guiTimer1S = 30000; 
}


// 定时器0中断处理函数
void isr_timer0() interrupt 1
{
	guiTimer1S--;

	if (0 == guiTimer1S)
	{
		guiTimer1S = 1000;			
		
		LED4 = ~LED4;
		LED5 = ~LED5;
	}				   	
}

// 串行口中断处理函数
void isr_uart() interrupt 4
{
	if (RI) 
	{
		return;
	}
	
	if (TI)
	{
	}
}
