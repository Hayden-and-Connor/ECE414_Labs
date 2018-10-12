#include "uart.h"

void uart_test_linked(){}

static int echo;

static void init(){
	TRISA = ~0;
	ANSELA = 0;

	U1RXR = 0;
	RPA0R = 1;
	U1BRG = 259;

	U1MODE &= ~(1 << 3);
	U1STA |= ((1 << 12) | (1 << 10));
	U1MODE |= (1 << 15);

	uart_char = EVENT_LOOP.new_handler();
	uart_line = EVENT_LOOP.new_handler();

	echo = 1;
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
}

static int write_ready(){
	return !(U1STA & (1 << 9));
}

static int read_ready(){
	return (U1STA & (1 << 0));
}

static void nb_write(char input) {
	if(U1STA & (1 << 9)) return;
	U1TXREG = input;
}

static char nb_read() {
	if(U1STA & (1 << 0)){
		return U1RXREG;
	} else {
		return '\0';
	}
}

static void write_string(char input[]){
	int index = 0;
	while(input[index] != '\0'){
		busy_write(input[index]);
		index ++;
	}
}

static int read_buffer_index = 0;

static void listen(){
	static char next;

	static char read_buffer[64];

	if(read_buffer_index > 63){
		read_buffer_index = 0;
	}

	next = '\0';
	next = UART.nb_read();

	if(next == '\0') return;

	if(next == 127 || next == 8 || next == 27) return;

	if(next == '\n' || next == '\r') {
		
		//write_string(read_buffer);
		if(echo) write_string("\n \r"); //echo

		read_buffer[read_buffer_index] == '\0'; // should replace \n or \r at end of string with null character
		read_buffer_index = 0;
		EVENT_LOOP.emit(uart_line, &read_buffer);
		return;
	}

	if(echo) busy_write(next); // echo
	read_buffer[read_buffer_index] = next;
	read_buffer_index++;
	EVENT_LOOP.emit(uart_char, &next);
	
}

static void clear_buffer(){
	read_buffer_index = 0;
}

uart_interface UART = {
	&init,

	&busy_write,
	&busy_read,

	&nb_write,
	&nb_read,

	&write_ready,
	&read_ready,

	&write_string,

	&listen,

	&clear_buffer,
	&echo
};
