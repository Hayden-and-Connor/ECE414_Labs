#ifndef CALCULATOR_C
#define CALCULATOR_C

// #include <stdlib>

// OPERATOR MACROS
#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define EQUAL '='

// STATE MACROS
// least significant bit determines which register to edit
// 2nd least significant bit determines whether or not to clear 
// parameter when digit is pressed depending on if an operator was 
// last pressed
#define EDIT_PARAM_0 0
#define EDIT_PARAM_1 1
#define OVERRIDE_PARAM_0 2
#define OVERRIDE_PARAM_1 3

// min signed int:       - 2 , 1 4 7 , 4 8 3 , 6 4 7 \0
// index of char in hex: 0 1 2 3 4 5 6 7 8 9 a b c d e
#define MAX_DISPLAY_CHAR 15 

static int param[2]; 
static char operator;
//static disp
static char display[12];
static int state;

typedef struct{
	char* display;
	int* state;
} calculator;

calculator CALCULATOR = {
	&display,
	&state
};

void init_calculator(){
	state = 0;

	param[0] = 0;
	param[1] = 0;
	operator = '\0';
	int i;
	for(i = 0; i < MAX_DISPLAY_CHAR; i++){
		display[i] = '\0';
	}
}

void add_digit(int param_index, int digit){
	// check for overflow
	if((param[param_index] & 0x7fffffff) * 10 + digit < 0){
		sprintf(display, "Error OverFlow"); // update display str in mem
		return;
	}
	// valid entry
	param[param_index] *= 10;
	param[param_index] += digit;
	sprintf(display, "%d", param[param_index]); // update display str in mem
}

void clear_param(int param_index){
	param[param_index] = 0;
}

void digit_pressed(int digit){
	if(state & 2){
		// override state - clear
		clear_param(state & 1);
	} 
	if(state & 1){
		add_digit(1, digit);
	} else {
		add_digit(0, digit);
	}
}

// performs calcuation with current operator and stores in param[0]
void calculate(){
	if(operator == ADD){
		param[0] += param[1];
	} else if(operator == SUBTRACT){
		param[0] -= param[1];
	} else if(operator == MULTIPLY){
		param[0] *= param[1];
	} else if(operator == DIVIDE){
		if (param[1] == 0){
			sprintf(display, "Error Div by 0");
			return;
		}
		param[0] /= param[1];
	}
	sprintf(display, "%d", param[0]); 
}

void operator_pressed(char op){
	if(op == EQUAL){
		calculate(); // result stored in param[0] and display ptr is updated
		state = OVERRIDE_PARAM_0;
	} else {
		operator = op;
		if(state & 1){
			calculate();
			state = OVERRIDE_PARAM_1;
		} else {
			param[1] = param[0];
			state = OVERRIDE_PARAM_1;
			sprintf(display, "%d", param[1]); 
		}
	}
}

#endif
