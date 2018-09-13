#include "TouchScreen.h"
#include <stdint.h>
#include <stdio.h>

#define MAX_BUTTONS 10
#define THRESHOLD 1

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define DEFAULT_COLOR 0x8bef

typedef struct TSPoint TSPoint;

typedef struct {
	int16_t x, y, width, height, color, active;
} Button;

int colorCount = 6;
int16_t colors[10] = {0x0000, 0xf800, 0x07e0, 0x001f, 0x07ff, 0xffe0}; 

static int buttonCount = 0;
static Button buttons[MAX_BUTTONS];

// makes button and adds it to management array
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

// switches the active state of butons to display only one iwth boarder
void switchTo(Button* button) {
	int i;
	for(i=0; i<buttonCount; i++) {
		buttons[i].active = 0;
	}

	button -> active = 1;
}

// returns true if point is within bounds of button
int contains(Button* button, TSPoint* point) {
	return 		point -> x > button -> x 
			&&	point -> x < (button -> x + button -> width)
			&&	point -> y > button -> y 
			&&	point -> y < (button -> y + button -> height);
}

// returns pointer to button that is pressed
// return NULL if none
Button* detectPress(TSPoint* input) {
	int i;
	for(i=0; i< buttonCount; i++) {
		if(contains(&(buttons[i]), input)) return &(buttons[i]);
	}

	return NULL;
}

// draws single button
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

// draws all buttons
void draw_buttons(){
	tft_fillRect(
		SCREEN_WIDTH -33,
		SCREEN_HEIGHT - (30 * (colorCount + 1)),
		33,
		30 * (colorCount + 1),
		0xffff
	);

	int i;
	for(i = 0; i < buttonCount; i++){
		draw(&buttons[i]);
	}
}