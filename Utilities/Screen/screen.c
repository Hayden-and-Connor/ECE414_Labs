#ifndef SCREEN_C
#define SCREEN_C

#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.h"
#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c"

#include <plib.h>
#include <xc.h>
#include "Utilities/Screen/adc_intf.h"
#include "Utilities/Screen/TouchScreen.h"

#include "Utilities/vector.c"

#define SCREEN_WIDTH	320
#define SCREEN_HEIGHT	240

typedef struct TSPoint TSPoint;

typedef struct click_event {
	Vector2 position;
} click_event;

typedef void (*click_handler)(click_event*);

static void init() {
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

static TSPoint new_getPoint(){
	TSPoint p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    getPoint(&p);
    return p;
}

static void listen() {
	TSPoint point new_getPoint();

	
}

// declare an interface for talking with this module
// (lets us call functions with the dot operator, which 
// helps keep the global namespace clean and aids in debugging)
typedef struct {
	TSPoint (*getPoint)();
	void (*init)();
} screen_interface;

screen_interface SCREEN = { 
	&new_getPoint, 
	&init
};

#endif