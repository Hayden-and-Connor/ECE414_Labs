#include "keypad.h"

void keypad_test_linked(){}

static void init(){
	// Enable Pull Up resitors on input pins for scanning
	ANSELB = 0;
	TRISB = 0x0780; // RB7, RB8, RB9, RB10 inputs / RB0 - RB3 output

	CNPUB = 0x0780; // pull up on RB7, RB8, RB9, RB10  0111 1000 0000
	CNPDB = 0x0000;

	PORTB = 0x000E;
}

static void listen(){
	// sprintf(write_buffer, "%X \n \r", PORTB);
	// UART.write_string(write_buffer);
}