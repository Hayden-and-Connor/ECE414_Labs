#ifndef ENCODER_H
#define ENCODER_H

#include "Utilities/uart.h"
#include <p32xxxx.h>
#include <plib.h>


// please use PORTB
#define CHN_A 14
#define CHN_B 15

// void init();

// must be called as frequently as possible
// void poll();

void encoder_init();
void encoder_poll();

typedef struct _encoder_interface {
	void (*init)();
	void (*poll)();
} encoder_interface;

encoder_interface ENCODER;

#endif