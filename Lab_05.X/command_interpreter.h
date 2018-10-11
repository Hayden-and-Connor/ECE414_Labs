#ifndef COMMAND_INTERPRETER
#define COMMAND_INTERPRETER

typedef enum _global_state {
	MAIN,
	ANALOG_INPUT,
	ENCODER,
	KEYPAD
} global_state;


global_state currentState = MAIN;



#endif