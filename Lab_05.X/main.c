#include "Utilities/KeyPad/keypad.h"
//#include "Utilities/event_handler.h"

#include "Utilities/uart.h"
#include <stdio.h>

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

uint8_t buffer[64];

void main(){
	UART.init();
	int i;

	analog_in_init();
	int32_t volt = 0;
    
    int32_t count = 0;
	

	while(1){
		// encoder read
		

		// // working analog read
		// volt = analog_in_read(9);
		// sprintf(buffer, "%04d    \r \n");
		// UART.write_string(buffer);
		// for(i = 0; i < 1000000; i++){

		// }
	}
}