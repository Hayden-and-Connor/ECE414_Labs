#include "uart.h"

test(){
	
}

static void init(){
	// TRISA = ~0;
	// ANSELA = 0;

	// TRISB = ~0;
	// ANSELB = 0;

	// U1RXR = 0;
	// // RPB7R = 1;
	// RPA0R = 1; // set pin 4 to RPA0
	// U1BRG = 259;

	// // U1MODE = 8;
	// U1MODE &= ~(1 << 3);
	// U1STA |= ((1 << 12) | (1 << 10));
	// U1MODE |= (1 << 15);
	// U1MODEbits.ON = 1;
}

static void write(char input) {
	while(1) {
		int isReady = !(U1STA & (1 << 9)); 

		if(isReady) {
			U1TXREG = input;
			break;
		}
	} 
}

uart_interface UART = {
	&init,
	&write
};