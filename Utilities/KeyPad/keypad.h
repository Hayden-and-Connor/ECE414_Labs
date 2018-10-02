#ifndef KEYPAD_H
#define KEYPAD_H

typedef enum state {
	UP, DOWN
} STATE;

typedef struct key_event {
	char key;
	STATE state;
} key_event;

typedef void (*key_handler)(key_event);



typedef struct keypad_interface {

} keypad_interface;

keypad_interface KEYPAD;

#endif