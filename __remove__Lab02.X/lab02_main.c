/* 
 * File:   lab02_main.c
 * Author: winiarcc
 *
 * Created on September 9, 2018, 3:44 PM
 */

#define _SUPPRESS_PLIB_WARNING 1

// Configure clocks
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#include "tft_master.h"
#include "tft_gfx.h"

#include <stdlib.h>
#include <inttypes.h>

// touch example imports
#include "config.h"
#include "plib.h"
#include "xc.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"


// Convenient defines for width and height of display
#define DW          320
#define DH          240
#define MAX_RAD     50

// touch example
#define XM AN0
#define YP AN1

//void main()
//{   
//    static int8_t buffer[64];
//    uint32_t i, idx;
//    
//    // Turn off analog function of Ports A and B
//    ANSELA = 0; 
//    ANSELB = 0; 
//    
//    // Turn off comparator functions
//    CM1CON = 0; 
//    CM2CON = 0;
//    
//    // Initialize TFT
//    tft_init_hw();
//    tft_begin();
//
//     tft_setRotation(3);  // Landscape mode.  Use 1 for portrait.
//
//    idx = 0;
//    while (1)
//    {
//        // Clear the screen
//        tft_fillScreen(ILI9341_BLACK);
//
//        // Draw some text
//        tft_setCursor(0, 0);  // Upper Left Hand Corner
//        tft_setTextColor(ILI9341_WHITE);  tft_setTextSize(2);
//
//        tft_writeString("Hello World.");
//        for (i=1; i<10; i++)
//        {
//            tft_setCursor(0, i*20);
//            sprintf(buffer, "The index is %d", idx++);
//            tft_writeString(buffer);        
//        }
//
//        // Draw some random lines.  Note: Avoid using rand() function in
//        // performance critical code!    
//        for (i=0; i<10; i++)
//        {
//            tft_drawLine(rand() % DW, rand() % DH, rand() % DW, rand() % DH, rand() & 0xffff);
//        }
//
//        // Draw some random filled circles
//        for (i=0; i<10; i++)
//        {
//            tft_fillCircle(rand() % (DW-2*MAX_RAD) + MAX_RAD, rand() % (DH-2*MAX_RAD) + MAX_RAD, rand() % MAX_RAD, rand() & 0xffff);
//        }
//
//        // Wait a bit.  In real code, use a timer!
//        for (i=0; i<1000000; i++) { }        
//    }    
//    
//}

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


