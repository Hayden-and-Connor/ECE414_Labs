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

char buffer[64];

void clear(click_event* event) {
	tft_fillScreen(0xffff);
}

void fill(click_event* event){
	tft_fillScreen(0x0000);
}

void log_click(click_event* event){
	tft_fillScreen(0xffff);

	tft_setCursor(10, 100);  // Upper Left Hand Corner
	tft_setTextColor(0x0000);  tft_setTextSize(2);
	sprintf(buffer, "last touch (%d, %d)", 
		event -> position.x, 
		event -> position.y
	);

	tft_writeString(buffer);
}


void main() {

	// SCREEN.on_touch_up( &clear );
	// SCREEN.on_touch_down( &fill );

	SCREEN.on_touch_down( &log_click );

    uint32_t i, idx;
    
    SCREEN.init();
    tft_fillScreen(0xffff);
    Vector2 a = {3, 4};
    Vector2 b = {1, 7};

    Vector2 test = VECTOR.add(a, b);

    idx = 0;

	sprintf(buffer, "UP");
	tft_setTextColor(0x0000);
	tft_setCursor(10, 10);
	tft_writeString(buffer);

	tft_fillScreen(0x0000);


   while (1) {
   		// sprintf(buffer, "UP");
   		// tft_setTextColor(0x0000);
   		// tft_setCursor(10, 10);
   		// tft_writeString(buffer);

		SCREEN.listen();

   		struct TSPoint p, np;

       	p = SCREEN.getPoint();
  //      	if(p.z > 2){
  //      		np = p;
		// }



		// Clear the screen
		// tft_fillScreen(0xffff);

		// // Draw some text
		// tft_setCursor(10, 10);  // Upper Left Hand Corner
		// // tft_setTextColor(0x0000);  tft_setTextSize(2);
		// // sprintf(buffer, "hello (%d, %d) + (%d, %d) = (%d, %d)", a.x, a.y, b.x, b.y, test.x, test.y);

		// tft_writeString(buffer);

		// tft_setCursor(10, 100);  // Upper Left Hand Corner
		// tft_setTextColor(0xffff); tft_setTextSize(2);
		// tft_writeString(buffer);

		// tft_setCursor(10, 100);  // Upper Left Hand Corner
		// tft_setTextColor(0x0000);  tft_setTextSize(2);
		// sprintf(buffer, "last touch (%d, %d, %d)", p.x, p.y, p.z);

		// tft_writeString(buffer);

		delay_ms(1);

   } 
    
    // while(1){
    //     // tft_fillScreen(ILI9341_BLACK);
    //     tft_setCursor(20, 100);
    //     tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);

    //     //erase old text
    //     tft_setTextColor(ILI9341_BLACK);
    //     tft_writeString(buffer);
        
    //     struct TSPoint p;
    //     p.x = 0;
    //     p.y = 0;
    //     p.z = 0;
    //     getPoint(&p);
    //     // struct TSPoint np;
    //     // np = map_touch_to_pixels(p);
    //     tft_setCursor(20, 100);
    //     tft_setTextColor(ILI9341_WHITE);
    //     // sprintf(buffer,"x: %d, y: %d, z: %d", np.x, np.y, np.z);
    //     sprintf(buffer,"x: %d, y: %d, z: %d", p.x, p.y, p.z);
    //     tft_writeString(buffer);
    
    //     delay_ms(100);
    // }
}
