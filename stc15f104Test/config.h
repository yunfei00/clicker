#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "STC15F104E.h"

#if defined(SDCC) || defined(__SDCC)
#define IDATA __idata
#define INTERRUPT(vector) __interrupt(vector)
#define SBIT_AT(name, address) __sbit __at(address) name
#else
#define IDATA idata
#define INTERRUPT(vector) interrupt vector
#define SBIT_AT(name, address) sbit name = address
#endif

#endif