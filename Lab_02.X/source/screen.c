#include "TouchScreen.h"
#include <stdint.h>
#include <stdio.h>

#define MAX_BUTTONS 10
#define THRESHOLD 1

#define DEFAULT_COLOR 0x8bef

typedef struct TSPoint TSPoint;

typedef struct {
	int16_t x, y, width, height, color, active;
} Button;

// typdef struct {
// 	int16_t x, y, width, height;
// 	void (*draw)(*Element);
// } Element;

static int buttonCount = 0;
static Button buttons[MAX_BUTTONS];

Button* newButton(int16_t x, int16_t y, int16_t width, int16_t height){
	if(buttonCount >= MAX_BUTTONS - 1) return NULL; // NO BUTTON FOR YOU! NEXT!

	Button output;
	output.x = x;
	output.y = y;
	output.width = width;
	output.height = height;
	output.color = DEFAULT_COLOR;

	buttons[buttonCount] = output;
	buttonCount ++;

	return &buttons[buttonCount - 1];
}

void switchTo(Button* button) {
	int i;
	for(i=0; i<buttonCount; i++) {
		buttons[i].active = 0;
	}

	button -> active = 1;
}

int contains(Button* button, TSPoint* point) {
	return 		point -> x > button -> x 
			&&	point -> x < (button -> x + button -> width)
			&&	point -> y > button -> y 
			&&	point -> y < (button -> y + button -> height);
}

Button* detectPress(TSPoint* input) {
	if(input -> z < THRESHOLD) return NULL;

	int i;
	for(i=0; i< buttonCount; i++) {
		if(contains(&(buttons[i]), input)) return &(buttons[i]);
	}

	return NULL;
}

void draw(Button* button) {
	if(button -> active){
		tft_fillRect(
			button -> x - 3,
			button -> y - 3,
			button -> width + 6,
			button -> height + 6,
			0x0000
		);	
	}
	
	tft_fillRect(
		button -> x,
		button -> y,
		button -> width,
		button -> height,
		button -> color
	);
}

void draw_buttons(){
	int i;
	for(i = 0; i < buttonCount; i++){
		draw(&buttons[i]);
	}
}