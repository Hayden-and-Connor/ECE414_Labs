#define _SUPPRESS_PLIB_WARNING 1

// Configure clocks
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20 //40 MHz
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2 // PB 40 MHz
#pragma config FWDTEN = OFF,  FSOSCEN = OFF, JTAGEN = OFF

#include "Utilities/vector.c"
#include "Utilities/Screen/screen.c"

// Convenient defines for width and height of display
#define SCREEN_WIDTH	320
#define SCREEN_HEIGHT	240
// #define MAX_RAD	50

void main() {
	static int8_t buffer[64];
    uint32_t i, idx;
    
    // Turn off analog function of Ports A and B
    // ANSELA = 0; 
    // ANSELB = 0; 
    
    // // Turn off comparator functions
    // CM1CON = 0; 
    // CM2CON = 0;
    
    // // Initialize TFT
    // tft_init_hw();
    // tft_begin();

    // tft_setRotation(1);

    screen_init();

    Vector2 a = {3, 4};
    Vector2 b = {1, 7};

    Vector2 test = VECTOR.add(a, b);

    idx = 0;
    while (1)
    {

    	struct TSPoint p, np;
    	p.x = 0;
	    p.y = 0;
	    p.z = 0;
        np.x = 0;
        np.y = 0;
        np.z = 0;
        p = new_getPoint();
        if(p.z > 2){
        	np = p;
        }
        // Clear the screen
        // tft_fillScreen(0xffff);

        // Draw some text
        tft_setCursor(10, 10);  // Upper Left Hand Corner
        tft_setTextColor(0x0000);  tft_setTextSize(2);
        sprintf(buffer, "hello (%d, %d) + (%d, %d) = (%d, %d)", a.x, a.y, b.x, b.y, test.x, test.y);

        tft_writeString(buffer);

        tft_setCursor(100, 100);  // Upper Left Hand Corner
        tft_setTextColor(0x0000);  tft_setTextSize(2);
        sprintf(buffer, "last touch (%d, %d)", np.x, np.y);

        tft_writeString(buffer);

    }
}