#ifndef TIMER_MS_H
#define TIMER_MS_H

#include <p32xxxx.h>
#include <inttypes.h>
#include <plib.h>

typedef struct timer_interface{
	void (*init)();
	int (*read)();
	void (*delay_ms)(int);
} timer_interface;

timer_interface TIMER;

#endif
