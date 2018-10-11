#include "Utilities/KeyPad/keypad.h"
#include "Utilities/uart.h"
#include "Utilities/event_loop.h"
#include "Utilities/Analog_In/analog_in.h"

#include <stdlib.h>

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

char write_buffer[64];

typedef enum _mode {
	MAIN,
	ANALOG_INPUT,
	ENCODER,
	KEYPAD_MATRIX
} MODE;

MODE mode = MAIN;
int analogPin;

void print_char(const void* data) {
	char value = *(char*)(data);

	UART.busy_write(value);
}

void on_command(const void* data) {
	static char* buffer;

	if(mode != MAIN) return;

	buffer = (char*)(data);
	char command = buffer[0];

	switch(command) {
		case 'a':
			mode = ANALOG;


			break;
	}

	UART.busy_write('\n');
	UART.busy_write('\r');
}

void on_char(const void* data) {
	char value = *(char*)(data);

	if(value == 'q') mode = MAIN;
}

void main(){
	UART.init();
	KEYPAD.init();
	analog_in_init();

	EVENT_LOOP.on(uart_line, &on_command);
	EVENT_LOOP.on(uart_char, &on_char);

	EVENT_LOOP.on(uart_char, &print_char); // set uart to echo

	while(1){
		
		switch(mode) {
			case MAIN:
				UART.write_string("MAIN\n\r");
				break;
			case ANALOG_INPUT:
				UART.write_string("ANALOG\n\r");
				break;
			default: UART.write_string("Its broken");

		}
		
		KEYPAD.listen();
		UART.listen();
		
	}

	
////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
	// Encoder
	// ANSELB &= ~(1 << 13);
	// ANSELB &= ~(1 << 14);
	// TRISB |= (1 << 13);
	// TRISB |= (1 << 14);


	// sprintf(write_buffer, "Encoder test: \r \n");
	// UART.write_string(write_buffer);

	// int i, encoder_sub, encoder_sub_prev, dir, count;
	// count = 0;
	// while(1){
	// 	encoder_sub_prev = encoder_sub;
	// 	encoder_sub = (PORTB & (1 << 13)) >> 13;
	// 	encoder_sub |= (PORTB & (1 << 14)) >> 13;
		
	// 	if(encoder_sub == 3){
	// 		if(encoder_sub_prev == 2){
	// 			count++;
	// 			sprintf(write_buffer, "%d \r \n", count);
	// 			UART.write_string(write_buffer);
	// 		} else if(encoder_sub_prev == 1){
	// 			count--;
	// 			sprintf(write_buffer, "%d \r \n", count);
	// 			UART.write_string(write_buffer);
	// 		}
			
	// 	}
		
	// 	for(i = 0; i < 1000; i++){

	// 	}
	// }
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// working analog read
// 	UART.init();
// 	int i;

// 	analog_in_init();
// 	int32_t volt = 0;
// 	while(1){
// 		// volt = analog_in_read(9);
// 		// sprintf(write_buffer, "%04d    \r \n");
// 		// UART.write_string(write_buffer);
// 		// for(i = 0; i < 1000000; i++){

// 		// }
// 	}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

}

