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

#define TS_X_MIN 150
#define TS_X_MAX 900
#define TS_Y_MIN 50
#define TS_Y_MAX 950

typedef enum state {
	UP,
	DOWN
} STATE;

typedef struct TSPoint TSPoint;
typedef struct struct_click_event {
	Vector2 position;
	STATE state;
} click_event;

typedef void (*click_handler)(click_event*);

#define MAX_LISTENERS 10

static int up_listeners_size = 0;
click_handler up_listeners[MAX_LISTENERS];

static int down_listeners_size = 0;
click_handler down_listeners[MAX_LISTENERS];

static int hold_listeners_size = 0;
click_handler hold_listeners[MAX_LISTENERS];

static void on_touch_down(click_handler handler) {
	if(down_listeners_size >= MAX_LISTENERS) return;

	down_listeners[down_listeners_size] = handler;
	down_listeners_size ++;
}

static void on_touch_up(click_handler handler) {
	if(up_listeners_size >= MAX_LISTENERS) return;

	up_listeners[up_listeners_size] = handler;
	up_listeners_size ++;
}

static void on_touch_hold(click_handler handler) {
	if(hold_listeners_size >= MAX_LISTENERS) return;

	hold_listeners[hold_listeners_size] = handler;
	hold_listeners_size ++;
}

static void screen_init() {
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

Vector2 map_touch_to_pixels(Vector2 input){
	return VECTOR.new(
		(((input.y - TS_Y_MIN) * (SCREEN_WIDTH))/(TS_Y_MAX - TS_Y_MIN)),
		SCREEN_HEIGHT - ((input.x - TS_X_MIN) * SCREEN_HEIGHT) / (TS_X_MAX - TS_X_MIN)
	);
}

#define THRESHOLD 10
static void listen() {
	static click_event current_event;

	static STATE previous_state = UP;
	static STATE current_state;

	//get point
	TSPoint point = new_getPoint();
	current_state = (point.z > THRESHOLD && point.z <  600) ? DOWN : UP;

	// touch up
	if(current_state == UP && previous_state == DOWN) {
		Vector2 position = {point.x, point.y};
		position = map_touch_to_pixels(position);
		current_event.position = position;
		current_event.state = UP;

		int i;
		for(i=0; i < up_listeners_size; i++) {
			up_listeners[i]( &current_event );
		}
	}

	// touch down
	if(current_state == DOWN && previous_state == UP) {
		Vector2 position = {point.x, point.y};
		position = map_touch_to_pixels(position);
		current_event.position = position;
		current_event.state = DOWN;

		int i;
		for(i=0; i < down_listeners_size; i++) {
			down_listeners[i]( &current_event );
		}
	}

	// touch hold
	if(current_state == DOWN && previous_state == DOWN) {

	}

	previous_state = current_state;
}

char buffer[64];

// declare an interface for talking with this module
// (lets us call functions with the dot operator, which 
// helps keep the global namespace clean and aids in debugging)
typedef struct {
	TSPoint (*getPoint)();
	void (*init)();
	void (*on_touch_up)(click_handler);
	void (*on_touch_down)(click_handler);
	void (*on_touch_hold)(click_handler);
	void (*listen)();
	// char buffer[64];
} screen_interface;

screen_interface SCREEN = { 
	&new_getPoint, 
	&screen_init,
	&on_touch_up,
	&on_touch_down,
	&on_touch_hold,
	&listen
};

#endif