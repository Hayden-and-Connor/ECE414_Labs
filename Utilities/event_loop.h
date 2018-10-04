#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H

typedef void(*event_listener)(const void*);

#define MAX_LISTENERS 10
typedef struct _event_handler {
	int size;
	event_listener listeners[MAX_LISTENERS];
} event_handler;

typedef struct _event_loop_interface {
	event_handler* (*new_handler)();
	void (*on)(event_handler*, event_listener);
	void (*emit)(event_handler*, void*);
} event_loop_interface;

event_loop_interface EVENT_LOOP;

// void on(event_handler* event, event_listener listener);

#endif