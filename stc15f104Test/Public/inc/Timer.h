#ifndef _TIMER_H
#define _TIMER_H

#include "../../config.h"
#include "RS-232.h"

#define TIME0_INITIAL       0x06

extern void timer0_initial(void);
extern void timer1_initial(void);

#endif