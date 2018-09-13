#ifndef SCREEN_C
#define SCREEN_C

#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.h"
#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c"

#define SCREEN_WIDTH	320
#define SCREEN_HEIGHT	240

// void 

void screen_init() {
	ANSELA = 0; 
	ANSELB = 0; 
	
	// Turn off comparator functions
	CM1CON = 0; 
	CM2CON = 0;
	
	// Initialize TFT
	tft_init_hw();
	tft_begin();

	tft_setRotation(1);
}

#endif