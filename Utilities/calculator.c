#ifndef CALCULATOR_C
#define CALCULATOR_C

#include <stdlib>

#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'

// min signed int:       - 2 , 1 4 7 , 4 8 3 , 6 4 7 \0
// index of char in hex: 0 1 2 3 4 5 6 7 8 9 a b c d e
#define MAX_DISPLAY_CHAR 15 

static int param[2]; 
static char operator;
static char display[12];

typedef struct{
	char* display;
} calculator;

calculator CALCULATOR = {
	&display;
}

void init_calculator(){
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
	if(param[param_index] > 0){
		// positive overflow
		if(param[param_index]*10 + digit < 0){
			sprintf(display, "Error OverFlow"); // update display str in mem
			return;
		}
	} 
	// valid entry
	param[param_index] *= 10;
	param[param_index] += digit;
	sprint(display, "%d", param[param_index]); // update display str in mem
}

void digit_pressed(int digit){
	if(operator == '\0'){
		add_digit(0, digit);
	} else {
		add_digit(1, digit);
	}
}

// void operator_pressed(char operator){
// 	if(param[1] !=){

// 	}
// }

// void clear_entry(){

// }

// void clear_pressed(){

// }



// void digit_press(int digit){
// 	if(operator == NULL){
// 		&
// 	}
// }

// void add_operator(char operator){
// 	c->operator = operator;
// }

// int calculate(){
// 	if(c->param[0] == NULL || c->param[1] == NULL){
// 		return NULL;
// 	}
// 	if(c->operator == ADD){
// 		return c->param[0] + c->param[1];
// 	} else if(c->operator == SUBTRACT){
// 		return c->param[0] - c->param[1];
// 	} else if(c->operator == MULTIPLY){
// 		return c->param[0] * c->param[1];
// 	} else if(c->operator == DIVIDE){
// 		return c->param[0] / c->param[1];
// 	}
// 	return NULL;
// }

// void clear_param(int param_index){
// 	c->param[param_index] = NULL;
// }

// void clear_operator(){
// 	c->operator = NULL;
// }

// void clean_calculator(){
// 	clear_param(c, 0);
// 	clear_param(c, 1);
// 	clear_operator(c);
// }

#endif
