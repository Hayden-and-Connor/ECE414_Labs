/* 
 * File:   touch_main.c
 * Author: watkinma
 *
 * Description: Prints out the detected position (x, y) of a press on the
 * touchscreen as well as the pressure (z).
 * 
 * IMPORTANT: For this example to work, you need to make the following 
 * connections from the touchpad to the PIC32:
 *  Y+ => AN1 (Pin 3)
 *  Y- => RA3 (Pin 10)
 *  X+ => RA4 (Pin 12)
 *  X- => AN0 (Pin 2)
 * 
 */

#include "config.h"
#include "plib.h"
#include "xc.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_master.h"
#include "Utilities/Adafruit_2_4_LCD_Serial_Library/tft_gfx.h"

#include "screen.c"

#define XM AN0
#define YP AN1

typedef struct {
	int16_t color;
	int size;
} Brush;

Brush brush = {
	.color = 0, 
	.size = 7
};

// flips input axis
// scale input to screen dimensions
struct TSPoint map_touch_to_pixels(struct TSPoint p){
    struct TSPoint np;
    np.z = p.z;
    np.y = ((p.x - 150) * (SCREEN_HEIGHT))/(900 - 150);
    np.x = SCREEN_WIDTH - (((p.y - 50) * (SCREEN_WIDTH))/(950 - 50));
    return np;
}

// paints a point on the screen based on current brush properties
void paint(TSPoint point) {
	// don't paint anything if we are within this rectangle
	if(
			point.y > SCREEN_HEIGHT - (30 * (colorCount + 1)) - (3*brush.size)
		&&	point.x > SCREEN_WIDTH - 30 - (3*brush.size)
	) return;

	// do the painting
	tft_fillCircle(point.x, point.y, brush.size, brush.color);
}

int main(int argc, char** argv) {

    // legacy setup
    SYSTEMConfigPerformance(PBCLK);
    configureADC();
    
    // initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_WHITE); 

    // create buttons for color selection
    int i;
    for(i = 0; i < colorCount; i++){
    	Button* new = newButton(SCREEN_WIDTH - 30, SCREEN_HEIGHT - (30 * (i + 1)), 25, 25);
    	new -> color = colors[i];
    	new -> active = (i == 0); // set first button to active
    }

    // set default color
    brush.color = colors[0];

    // make a clear screen button
    Button* clear_screen = newButton(SCREEN_WIDTH - 30, SCREEN_HEIGHT - (30 * (colorCount + 1)), 25, 25);;
    clear_screen -> active = 1;		// we want this to also be active
    clear_screen -> color = 0xffff;	// we also want it to be white

    draw_buttons();

    while(1) {
    	// get touch point
        struct TSPoint p = {0, 0, 0};
        getPoint(&p);   
        // map touch point to screen point     
        struct TSPoint np;
        np = map_touch_to_pixels(p);

        // check to see if the user is touching the screen
        if(np.z > THRESHOLD) {

        	//get the button that is being pressed, or NULL if none
        	Button* pressed = detectPress(&np);

        	if(pressed == NULL) paint(np); // no button is pressed, paint
        	else {
        		// process button logic
        		if(pressed == clear_screen) {
        			tft_fillScreen(ILI9341_WHITE);
        		} else {
        			switchTo(pressed);
        			clear_screen -> active = 1; // keep clear screen active (with boarder)
        			brush.color = pressed -> color;
        		}

        		draw_buttons();
        	}
    	}

        delay_ms(1);    
    }
    
    return (EXIT_SUCCESS);
}
