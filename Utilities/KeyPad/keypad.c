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
	int i;
	for(i = 0; i < 4; i++){
		ANSELB &= ~(1 << rowPins[i]); // turn off analog
		ANSELB &= ~(1 << colPins[i]); // turn off analog

		TRISB &= ~(1 << rowPins[i]); // set row pins as outputs
		TRISB |= (1 << colPins[i]);  // set col pins as inputs

		CNPUB |= (1 << colPins[i]); // turn on pull ups on inputs

		PORTB |= (1 << rowPins[i]); // turn on output rows
	}

	key_toggle = EVENT_LOOP.new_handler();
}

char buffer[60];

static void listen(){
	static key_event currentEvent;

	int i;
	int j;
	for(i=0; i<4; i++) {
		PORTB &= ~(1 << rowPins[i]);

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

				// add event to queue
				currentEvent.state = buttonStates[i][j];
				currentEvent.key = keys[i][j];

				EVENT_LOOP.emit(key_toggle, &currentEvent);
			}
		}

		for(j = 0; j < 4; j++){
			PORTB |= (1 << rowPins[j]);			
		}
	}
}

keypad_interface KEYPAD = {
	&init,
	&listen
};