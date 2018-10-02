#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#define ADD_EVENT_LISTENER(X) 

typedef void(*event_listener)();

#define MAX_LISTENERS 15
static event_listener[MAX_LISTENERS];

typedef struct event_handler {
	void (*listen)();

} event_handler;

#endif