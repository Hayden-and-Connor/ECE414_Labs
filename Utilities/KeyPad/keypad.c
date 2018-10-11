#include "keypad.h"

void keypad_test_linked(){}

static const int rowPins[4] = { 3, 2, 1, 0 };
static const int colPins[4] = { 7, 8, 9, 10 };


#define DEBOUNCE_THRESHOLD 200
static int debounce_counter[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
};

static STATE buttonStates[4][4] = {
	{ UP, UP, UP, UP },
	{ UP, UP, UP, UP },
	{ UP, UP, UP, UP },
	{ UP, UP, UP, UP }
};

static const char keys[4][4] = {
	{ '1', '2', '3', 'A' },
	{ '4', '5', '6', 'B' },
	{ '7', '8', '9', 'C' },
	{ '*', '0', '#', 'D' }
};

static void init(){

	// Enable Pull Up resitors on input pins for scanning
	ANSELB = 0;
	TRISB = 0x0780; // RB7, RB8, RB9, RB10 inputs, columns / RB0 - RB3 output, rows

	CNPUB = 0x0780; // pull up on RB7, RB8, RB9, RB10
	CNPDB = 0x0000;

	// set all row pins to high
	PORTB = 0x000F;

	key_toggle = EVENT_LOOP.new_handler();
}

char buffer[60];

static void listen(){
	static key_event currentEvent;

	int i;
	int j;
	for(i=0; i<4; i++) {
		PORTB &= ~(1 << rowPins[i]);

		int k;
		for(k=0; k<10000; k++) {}

		for(j=0; j<4; j++){
			STATE rawState = (PORTB & (1 << colPins[j])) ? UP : DOWN;

			if(buttonStates[i][j] != rawState){
				debounce_counter[i][j]++;
			} else {
				debounce_counter[i][j] = 0;
				continue;
			}

			if(debounce_counter[i][j] >= DEBOUNCE_THRESHOLD){
				debounce_counter[i][j] = 0;

				buttonStates[i][j] = rawState;

				sprintf(&buffer, "%c, %d, %d, %d, \n\r", keys[i][j], i, j, buttonStates[i][j]);
				UART.write_string(buffer);

				// add event to queue
				currentEvent.state = buttonStates[i][j];
				currentEvent.key = keys[i][j];

				EVENT_LOOP.emit(key_toggle, &currentEvent);
			}
		}

		PORTB = 0x000F;
	}

	// static char write_buffer[60];



	// int i;
	// while(1){
	// 	sprintf(write_buffer, "%X \n \r", PORTB);
	// 	UART.write_string(write_buffer);

	// 	for(i = 0; i < 100000; i++){}
	// }
}

keypad_interface KEYPAD = {
	&init,
	&listen
};