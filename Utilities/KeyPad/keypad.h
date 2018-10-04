#ifndef KEYPAD_H
#define KEYPAD_H

#include "Utilities/gpio.c"
#include "Utilities/event_loop.h"

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