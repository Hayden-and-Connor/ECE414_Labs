#include "Utilities/event_loop.h"

static event_handler* new_event_handler(){
	event_handler* output = malloc( sizeof(event_handler) );
	output -> size = 0;
}

void on(event_handler* event, event_listener listener){
	if(event -> size > MAX_LISTENERS) return;

	event -> listeners[event -> size] = listener;
	event -> size ++;
}
static void emit(event_handler* event, void* value){
	int i;
	for(i=0; i < event->size; i++) {
		event->listeners[i](value);
	}
}

event_loop_interface EVENT_LOOP = {
	&new_event_handler,
	&on,
	&emit
};