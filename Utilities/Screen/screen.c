#ifndef SCREEN_C
#define SCREEN_C

#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.h"
#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c"

#include <plib.h>
#include <xc.h>
#include "Utilities/Screen/adc_intf.h"
#include "Utilities/Screen/TouchScreen.h"
// #include "Utilities/Screen/TouchScreen.c"

#define SCREEN_WIDTH	320
#define SCREEN_HEIGHT	240

//this should be typdefed because we can't remember to type "struct
//and we've already wasted so much time
// typedef struct TSPoint TSPoint;

void screen_init() {
	ANSELA = 0; 
	ANSELB = 0; 
	
	// Turn off comparator functions
	CM1CON = 0; 
	CM2CON = 0;
	
    SYSTEMConfigPerformance(PBCLK);
    configureADC();
    
	// Initialize TFT
	tft_init_hw();
	tft_begin();

	tft_setRotation(1);
}

// void getPoint(struct TSPoint*p) {}

struct TSPoint new_getPoint(){
	struct TSPoint p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    getPoint(&p);
    return p;
}

#endif