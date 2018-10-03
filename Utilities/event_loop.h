#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H

typedef void(*event_listener)(void*);

#define MAX_LISTENERS 10
typedef struct _event_handler {
	int size;
	event_listener listeners[MAX_LISTENERS];
} event_handler;

event_handler* new_event_handler(){
	event_handler* output = malloc( sizeof(event_handler) );
	output -> size = 0;
}

void on(event_handler* event, event_listener listener){
	if(event -> size > MAX_LISTENERS) return;

	event -> listeners[event -> size] = listener;
	event -> size ++;
}
void emit(event_handler* event, void* value){
	int i;
	for(i=0; i < event->size; i++) {
		event->listeners[i](value);
	}
}

#endif