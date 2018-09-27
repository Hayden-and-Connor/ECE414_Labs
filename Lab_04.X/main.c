#include <stdlib.h>
#include <p32xxxx.h>
#include "Utilities/uart.h"
#include <plib.h>


// Configure clocks
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

// #include "Utilities/gpio.c"

void main( ) {
	TRISA = ~0;
	ANSELA = 0;

	TRISB = ~0;
	ANSELB = 0;

	U1RXR = 0;
	// RPB7R = 1;
	RPA0R = 1; // set pin 4 to RPA0
	U1BRG = 259;

	// U1MODE = 8;
	U1MODE &= ~(1 << 3);
	U1STA |= ((1 << 12) | (1 << 10));
	U1MODE |= (1 << 15);


	// UART.init();
	// initPin(0, OUTPUT);

	test();

	while(1) {
		UART.write('c');
		UART.write('\n');
		UART.write('\r');

	// 	while(1) {
	// 		int isReady = !(U1STA & (1 << 9)); 

	// 		if(isReady) {
	// 			U1TXREG = 'c';
	// 			break;
	// 		}
	// 	}
	// 	while(1) {
	// 		int isReady = !(U1STA & (1 << 9)); 

	// 		if(isReady) {
	// 			U1TXREG = '\n';
	// 			break;
	// 		}
	// 	}
	// 	while(1) {
	// 		int isReady = !(U1STA & (1 << 9)); 

	// 		if(isReady) {
	// 			U1TXREG = '\r';
	// 			break;
	// 		}
	// 	}
	} 
		// UART.write(0x55);
		// UART.write('\n');
		// UART.write('\r');
}