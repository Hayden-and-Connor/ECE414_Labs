#include "uart.h"

void uart_test(){

}

static void init(){
	TRISA = ~0;
	ANSELA = 0;

	U1RXR = 0;
	RPA0R = 1;
	U1BRG = 259;

	U1MODE &= ~(1 << 3);
	U1STA |= ((1 << 12) | (1 << 10));
	U1MODE |= (1 << 15);
}

static void busy_write(char input) {
	while(1) {
		int isReady = !(U1STA & (1 << 9)); 

		if(isReady) {
			U1TXREG = input;
			break;
		}
	}
}

static char busy_read(){
	while(1) {
		int dataReady = (U1STA & (1 << 0));

		if(dataReady) {
			return U1RXREG;
		}
	}
	// while(U1STA & (1 << 0)){}
	// return U1RXREG;
}

uart_interface UART = {
	&init,
	&busy_write,
	&busy_read
};