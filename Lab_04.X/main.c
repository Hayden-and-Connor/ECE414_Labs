#include <stdlib.h>
#include <p32xxxx.h>
#include "Utilities/uart.h"
// #include "Utilities/uart.c"
#include <plib.h>

// Configure clocks
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

void test_blocking() {
	while(1){
		char input = UART.busy_read();
		UART.busy_write(input);

		UART.busy_write('\r');
		UART.busy_write('\n');
	}
}

void test_non_blocking(){
	while(1){
		while(!UART.read_ready()){}
		char input = UART.nb_read();

		while(!UART.write_ready()){}
		UART.nb_write(input);
	}
}

void main() {
	UART.init();

	// test_blocking();
	test_non_blocking();
}
