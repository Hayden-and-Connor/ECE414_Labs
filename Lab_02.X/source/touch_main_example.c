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
#include "tft_master.h"
#include "tft_gfx.h"


#define XM AN0
#define YP AN1

struct TSPoint map_touch_to_pixels(struct TSPoint p){
    struct TSPoint np;
    np.z = p.z;
    np.y = 240 - (((p.y - 650) * (240))/(1000 - 650));
    np.x = ((p.x - 50) * (320))/(600 - 50);
    return np;
}

/*
 * 
 */
int main(int argc, char** argv) {
    char buffer[30];
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();
    
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9341_BLACK);  
    
    while(1){
        //tft_fillScreen(ILI9341_BLACK);
        tft_setCursor(20, 100);
        tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);

        //erase old text
        tft_setTextColor(ILI9341_BLACK);
        tft_writeString(buffer);
        
        struct TSPoint p;
        p.x = 0;
        p.y = 0;
        p.z = 0;
        getPoint(&p);
        struct TSPoint np;
        // np = map_touch_to_pixels(p);
        tft_setCursor(20, 100);
        tft_setTextColor(ILI9341_WHITE);
        //sprintf(buffer,"x: %d, y: %d, z: %d", np.x, np.y, np.z);
        sprintf(buffer,"x: %d, y: %d, z: %d", p.x, p.y, p.z);
        tft_writeString(buffer);
    
        delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}

