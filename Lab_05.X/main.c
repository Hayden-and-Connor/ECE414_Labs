#include "Utilities/KeyPad/keypad.h"
#include "Utilities/uart.h"
#include "Utilities/event_loop.h"

#include <stdlib.h>

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

char write_buffer[64];

void print_char(void* data) {
	char value = *(char*)(data);

	UART.busy_write(value);
}

void test_print(void* data) {
	UART.write_string("test \n");
}

char test = 'a';
void main(){
	UART.init();

	uart_test_linked();

	EVENT_LOOP.on(uart_char, &print_char);
	EVENT_LOOP.emit(uart_char, &test);


	while(1){
		UART.listen();
	}
}
	// sprintf(write_buffer, "hello %d", test_event -> size);
	// UART.write_string(write_buffer);

// // working analog read
// 	UART.init();
// 	int i;

// 	analog_in_init();
// 	int32_t volt = 0;
// 	while(1){
// 		// volt = analog_in_read(9);
// 		// sprintf(buffer, "%04d    \r \n");
// 		// UART.write_string(buffer);
// 		// for(i = 0; i < 1000000; i++){

// 		// }
// 	}
// }
