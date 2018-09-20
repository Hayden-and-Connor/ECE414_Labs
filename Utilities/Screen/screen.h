// #ifndef SCREEN_H
// #define SCREEN_H

// #include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.h"
// #include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.c"

// #include <plib.h>
// #include <xc.h>
// #include "Utilities/Screen/adc_intf.h"
// #include "Utilities/Screen/TouchScreen.h"

// #include "Utilities/vector.c"

// typedef enum state {
// 	UP,
// 	DOWN
// } STATE;

// typedef struct TSPoint TSPoint;
// typedef struct struct_click_event {
// 	Vector2 position;
// 	STATE state;
// } click_event;

// typedef void (*click_handler)(click_event*);

// typedef struct {
// 	TSPoint (*getPoint)();
// 	void (*init)();
// 	void (*on_touch_up)(click_handler);
// 	void (*on_touch_down)(click_handler);
// 	void (*listen)();
// } screen_interface;


// static void init();

// screen_interface SCREEN = {
// 	&init
// };

// // static TSPoint new_getPoint();
// // static void init();
// // static void on_touch_down( click_handler );
// // static void on_touch_up( click_handler );
// // static void listen();

// #endif