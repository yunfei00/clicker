#include "STC15F104E.h"

#include <string.h>
#include "Public/inc/RS-232.h"
#include "Public/inc/Timer.h"
#include "Public/inc/Delay.h"  

unsigned int IDATA guiTimer1S = 4000;

SBIT_AT(LED0, 0xB0);
SBIT_AT(LED1, 0xB1);
SBIT_AT(LED2, 0xB2);
SBIT_AT(LED3, 0xB3);
SBIT_AT(LED4, 0xB4);
SBIT_AT(LED5, 0xB5);

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

void isr_int0(void) INTERRUPT(0)
{
    guiTimer1S = 30000; 
}

void isr_int1(void) INTERRUPT(2)
{
    guiTimer1S = 30000; 
}


void isr_timer0(void) INTERRUPT(1)
void isr_uart(void) INTERRUPT(4)
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
