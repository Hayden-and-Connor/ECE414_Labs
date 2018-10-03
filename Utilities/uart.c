#include "uart.h"

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

#define MAX_LISTENERS 10
static int listeners_index = 0;
static uart_event_listener listeners[MAX_LISTENERS];

static void add_event_listener(uart_event_listener input) {
	if(listeners_index > MAX_LISTENERS) return;

	listeners[listeners_index] = input;
	listeners_index ++;
}

static void listen(){
	static int read_buffer_index = 0;
	static char read_buffer[64];

	char next = nb_read();
	if(next) {
		read_buffer[read_buffer_index] = next;
		read_buffer_index ++;

		int i;
		for(i=0; i<listeners_index; i++) {
			listeners[i](read_buffer);
		}
	}

	// if(next == '\n') {
	// 	read_buffer[read_buffer_index + 1] = 0;
	// 	int i;
		// for(i=0; i<listeners_index; i++) {
		// 	listeners[i](read_buffer);
		// }

	// 	sprintf("", read_buffer);
	// }
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

	&add_event_listener,
	&listen
};
