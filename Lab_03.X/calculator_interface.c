
#include "Utilities/Screen/screen.c"
#include "Utilities/vector.c"
#include "Utilities/calculator.c"

#define COLOR_PRIMARY 0xffee
#define COLOR_SECONDARY 0x0000

typedef struct button_struct {
	Vector2 position;
	Vector2 size;

	char label[3];

	click_handler onclick;
} button;

#define MAX_ELEMENTS 20
static int buttons_size = 0;
static button buttons[MAX_ELEMENTS];

button* newButton(Vector2 position, Vector2 size, char label) {
	if(buttons_size >= MAX_ELEMENTS) return;

	button output = {
		position, size, label
	};

	buttons[buttons_size] = output;

	buttons_size ++;
	return &(buttons[buttons_size - 1]);
}

static void onclick( click_event event ) {
	int i;
	for(i=0; i<buttons_size; i++) {}
}

static int point_inside_button(Vector2 point, button* button) {
	return	point.x > button -> position.x
		&&	point.x < button -> position.x + button -> size.x
		&&	point.y > button -> position.y
		&&	point.y < button -> position.y + button -> size.y;
}

void render_button(button* this) {
	const static border_width = 5;

	//border
	// tft_fillRect(
	// 	this->position.x - border_width >> 1,
	// 	this->position.y - border_width >> 1,
	// 	this->size.x + border_width,
	// 	this->size.y + border_width,
	// 	0x8888
	// );

	//body
	tft_fillRect(
		this->position.x,
		this->position.y,
		this->size.x,
		this->size.y,
		COLOR_SECONDARY
	);

	//label
	sprintf(buffer, this -> label);
	tft_setCursor(
		this -> position.x + (this -> size.x * .5),
		this -> position.y + (this -> size.y * .5)
	);
	// tft_setCursor(100, 100);
	tft_setTextColor(0xffff); tft_setTextSize(2);
	tft_writeString(buffer);
}

void render_all() {
	int i;
	for(i=0; i<buttons_size; i++) {
		render_button(buttons + i);
	}

	tft_fillRect(0, 0, 256, 59, 0xffff);
	tft_setCursor(10,10);
	tft_setTextColor(0x0000); tft_setTextSize(3);
	tft_writeString(CALCULATOR.display);
}

void clear_all(click_event* event) {
	tft_fillScreen(0xffff);
}

void handle_click(click_event* event) {

	int i;
	for(i=0; i<buttons_size; i++) {
		if( point_inside_button(event -> position, buttons + i) ) {
			(buttons + i) -> onclick(event);
		}
	}

	// if( point_inside_button(event -> position, test) ) {
	// 	clear_all(event);
	// } else {
 	render_all();
	// }
}

// REFACTOR TO BE MORE ELEGANT
void one_pressed(){ digit_pressed(1); }
void two_pressed(){ digit_pressed(2); }
void three_pressed(){ digit_pressed(3); }
void four_pressed(){ digit_pressed(4); }
void five_pressed(){ digit_pressed(5); }
void six_pressed(){ digit_pressed(6); }
void seven_pressed(){ digit_pressed(7); }
void eight_pressed(){ digit_pressed(8); }
void nine_pressed(){ digit_pressed(9); }
void zero_pressed(){ digit_pressed(0); }
void add_pressed(){ operator_pressed('+'); }
void subtract_pressed(){ operator_pressed('-'); }
void multiply_pressed(){ operator_pressed('*'); }
void divide_pressed(){ operator_pressed('/'); }
void equal_pressed(){ operator_pressed('='); }
void clear_pressed(){ init_calculator(); }

static void calculator_interface_init() {
	// REFACTOR TO BE MORE ELEGANT
	const Vector2 button_size = {64, 60};
	
	char symbol = '\0';

	int i;
	for(i=0; i< 10; i++) {
		Vector2 position = VECTOR.new(
			(i % 3) * button_size.x,
			((i / 3) + 1) * button_size.y
		);

		sprintf(&symbol, "%d", i+1);
		button* output = newButton(position, button_size, symbol);
	}

	char operators[7] = {'=', '-', '/', 'C', '0', '+', '*'};
	for(i=0; i<7; i++) {
		Vector2 position = VECTOR.new(
			(SCREEN_WIDTH - (((i / 4) + 1) * button_size.x)),
			(SCREEN_HEIGHT - (((i % 4)+ 1) * button_size.y))
		);

		button* output = newButton(position, button_size, operators[i]);
	}


	SCREEN.on_touch_down( &handle_click );


	buttons[0].onclick = &one_pressed;
	buttons[1].onclick = &two_pressed;
	buttons[2].onclick = &three_pressed;
	buttons[3].onclick = &four_pressed;
	buttons[4].onclick = &five_pressed;
	buttons[5].onclick = &six_pressed;
	buttons[6].onclick = &seven_pressed;
	buttons[7].onclick = &eight_pressed;
	buttons[8].onclick = &nine_pressed;
	buttons[9].onclick = &equal_pressed;
	buttons[10].onclick = &subtract_pressed;
	buttons[11].onclick = &divide_pressed;
	buttons[12].onclick = &clear_pressed;
	buttons[13].onclick = &zero_pressed;
	buttons[14].onclick = &add_pressed;
	buttons[15].onclick = &multiply_pressed;

	render_all();
}




typedef struct {
	void (*init)();
} calculator_interface;

calculator_interface UI = {
	&calculator_interface_init
};