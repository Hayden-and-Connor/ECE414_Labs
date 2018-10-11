// keypad.h
// 
// Please wire this so that it uses PORTB pins

#ifndef KEYPAD_H
#define KEYPAD_H

#include "Utilities/gpio.c"
#include "Utilities/event_loop.h"

#include "Utilities/uart.h"

#include <stdlib.h>

event_handler* key_toggle;

typedef enum state {
	UP, DOWN
} STATE;

typedef struct key_event {
	char key;
	STATE state;
} key_event;

typedef struct keypad_interface {
	void (*init)();
	void (*listen)();
} keypad_interface;

keypad_interface KEYPAD;

#endif