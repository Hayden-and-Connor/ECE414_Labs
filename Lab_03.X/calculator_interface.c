
#include "Utilities/Screen/screen.c"
#include "Utilities/vector.c"

#define COLOR_PRIMARY 0xffee
#define COLOR_SECONDARY 0x0000

typedef struct button_struct {
	Vector2 position;
	Vector2 size;

	char label;

	click_handler onclick;
} button;

#define MAX_ELEMENTS 15
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

void render_button(button* this) {
	const static border_width = 20;

	//border
	tft_fillRect(
		this->position.x - border_width << 1,
		this->position.y - border_width << 1,
		this->size.x + border_width,
		this->size.y + border_width,
		0x8888
	);

	//body
	tft_fillRect(
		this->position.x,
		this->position.y,
		this->size.x,
		this->size.y,
		COLOR_SECONDARY
	);

	//label
	sprintf(buffer, "asdfasdfasdfasdfasdfadsfa");
	tft_setCursor(
		this -> position.x + (this -> size.x * .5),
		this -> position.y + (this -> size.y * .5)
	);
	tft_setCursor(100, 100);
	tft_setTextColor(0x0000);
	tft_writeString(buffer);
}

void render_all() {
	int i;
	for(i=0; i<buttons_size; i++) {
		render_button(buttons + i);
	}
}

static void calculator_interface_init() {
	// add some dummy buttons
	button* test = newButton(
		VECTOR.new(30, 30),
		VECTOR.new(75, 75),
		'1'
	);


	render_all();
}




typedef struct {
	void (*init)();
} calculator_interface;

calculator_interface UI = {
	&calculator_interface_init
};