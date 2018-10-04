#include "Utilities/KeyPad/keypad.h"
#include "Utilities/uart.h"
#include "Utilities/event_loop.h"

#include <stdlib.h>

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

char write_buffer[64];

void on_uart_value(char* value){
	// sprintf(write_buffer, "test");
	UART.write_string("test");
}

void handle_test_event(void* data) {
	UART.write_string("a test was called \n");
}

void main(){
	UART.init();

	// event_handler* test_event = new_event_handler();

	// on(test_event, &handle_test_event);

	// test_event -> listeners[0] = &handle_test_event;
	// on(test_event, &handle_test_event);
	// on(test_event, &handle_test_event);

	// emit(test_event, NULL);

	// sprintf(write_buffer, "hello %d", test_event -> size);
	// UART.write_string(write_buffer);
	ANSELB &= ~(1 << 13);
	ANSELB &= ~(1 << 14);
	TRISB |= (1 << 13);
	TRISB |= (1 << 14);


	sprintf(write_buffer, "Encoder test: \r \n");
	UART.write_string(write_buffer);

	int i, encoder_sub, encoder_sub_prev, dir, count;
	count = 0;
	while(1){
		encoder_sub_prev = encoder_sub;
		encoder_sub = (PORTB & (1 << 13)) >> 13;
		encoder_sub |= (PORTB & (1 << 14)) >> 13;
		
		if(encoder_sub == 3){
			if(encoder_sub_prev == 2){
				count++;
				sprintf(write_buffer, "%d \r \n", count);
				UART.write_string(write_buffer);
			} else if(encoder_sub_prev == 1){
				count--;
				sprintf(write_buffer, "%d \r \n", count);
				UART.write_string(write_buffer);
			}
			
		}
		
		for(i = 0; i < 1000; i++){

		}
	}

// // working analog read
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
}