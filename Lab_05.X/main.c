#include "Utilities/KeyPad/keypad.h"
#include "Utilities/uart.h"
#include "Utilities/event_loop.h"

#include <stdlib.h>

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

char write_buffer[64];

void print_char(const void* data) {
	char value = *(char*)(data);

	UART.busy_write(value);
}

void on_command(const void* data) {
	static char* buffer;

	buffer = (char*)(data);
	char command = buffer[0];

	UART.busy_write('\n');
	UART.busy_write('\r');
}

char test = 'a';
void main(){
	UART.init();
	KEYPAD.init();

	EVENT_LOOP.on(uart_line, &on_command);
	EVENT_LOOP.on(uart_char, &print_char); // set uart to echo

	while(1){
		UART.listen();
		KEYPAD.listen();
	}
	// sprintf(write_buffer, "hello %d", test_event -> size);
	// UART.write_string(write_buffer);
	
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


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
	// Keypad Input

	// sprintf(write_buffer, "%X", (PORTB >> 12) | ((PORTB & 0x0800) >> 10));
	// UART.write_string(write_buffer);



	// Keep track of keypad state for level to pulse for event triggers
}

