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

	event_handler* test_event = new_event_handler();

	// on(test_event, &handle_test_event);

	// test_event -> listeners[0] = &handle_test_event;
	on(test_event, &handle_test_event);
	on(test_event, &handle_test_event);

	emit(test_event, NULL);

	// sprintf(write_buffer, "hello %d", test_event -> size);
	// UART.write_string(write_buffer);
}