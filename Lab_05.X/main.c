#include "Utilities/KeyPad/keypad.h"
#include "Utilities/uart.h"
#include "Utilities/event_loop.h"
#include "Utilities/Analog_In/analog_in.h"
#include "Utilities/Encoder/encoder.h"

#include <stdlib.h>

#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

char write_buffer[64];

typedef enum _mode {
	MAIN,
	ANALOG_INPUT,
	ENCODER_INPUT,
	KEYPAD_MATRIX
} MODE;

MODE mode = MAIN;
int analogPin;


void on_command(const void* data) {
	static char* buffer;

	if(mode != MAIN) return;

	buffer = (char*)(data);
	char command = buffer[0];

	//UART.write_string(buffer);
	// UART.busy_write('\n');
	// UART.busy_write('\r');

	if(command == 'a') {
		char arg = buffer[1];
		if(arg >= '0' && arg <= '9'){
			mode = ANALOG_INPUT;
			*UART.echo = 0;
			analogPin = arg - '0';	
			char message[32];
			sprintf(message, "Reading from AN%d ... \r\n", analogPin);
			UART.write_string(message);
		} else {
			UART.write_string("Invalid analog pin.\r\n>>");
		}
	}
	else if(command == 'm') {
		mode = KEYPAD_MATRIX;
		*UART.echo = 0;
		UART.write_string("Reading keypad matrix ... \r\n");
	}
	else if(command == 'e') {
		mode = ENCODER_INPUT;
		*UART.echo = 0;
		UART.write_string("Reading encoder ... \r\n");
	} else {
		UART.write_string(">>");
	}
}

void on_char(const void* data) {
	char value = *(char*)(data);

	if(value == 'q'){
		mode = MAIN;
		*UART.echo = 1;
		UART.clear_buffer();
		UART.write_string("\r\n>>");
	}
}

void print_key(const void* data){
	key_event value = *(key_event*)(data);

	if(value.state == DOWN) UART.busy_write(value.key);
}

void main(){
	UART.init();
	KEYPAD.init();
	ANALOG.init();
	//ENCODER.init();

	EVENT_LOOP.on(uart_line, &on_command);
	EVENT_LOOP.on(uart_char, &on_char);

	EVENT_LOOP.on(key_toggle, &print_key);

	//EVENT_LOOP.on(uart_char, &print_char); // set uart to echo

	ANSELB &= ~(1 << 13);
	ANSELB &= ~(1 << 14);
	TRISB |= (1 << 13);
	TRISB |= (1 << 14);

	int i, encoder_sub, encoder_sub_prev, dir, count;
	count = 0;

	while(1){
		UART.listen();
		if(mode == MAIN) {}
		else if(mode == ANALOG_INPUT) {
			sprintf(write_buffer, "\r %5d \033[0K", ANALOG.read(analogPin) );
			UART.write_string( write_buffer );
		}
		else if(mode == ENCODER_INPUT) {
			//UART.write_string("ENCODER \n\r");
			encoder_sub_prev = encoder_sub;
			encoder_sub = (PORTB & (1 << 13)) >> 13;
			encoder_sub |= (PORTB & (1 << 14)) >> 13;
			
			if(encoder_sub == 3){
				if(encoder_sub_prev == 2){
					UART.busy_write('+');
				} else if(encoder_sub_prev == 1){
					UART.busy_write('-');
				}
				
			}
			
			for(i = 0; i < 1000; i++){

			}
		}
		else if(mode == KEYPAD_MATRIX){
			KEYPAD.listen();
		}
	}
}

