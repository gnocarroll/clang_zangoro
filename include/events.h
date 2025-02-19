#ifndef EVENTS_H
#define EVENTS_H

#include <stdbool.h>

union SDL_Event;

void handle_event(const union SDL_Event* event);

// should_quit will indicate if app should shut down

bool get_should_quit();

#endif // EVENTS_H
