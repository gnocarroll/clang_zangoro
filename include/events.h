#ifndef EVENTS_H
#define EVENTS_H

#include <stdbool.h>

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>

#include "mynumdef.h"

union SDL_Event;

void handle_event(const union SDL_Event* event);

// should_quit will indicate if app should shut down

bool get_should_quit();

// functions to get information on keyboard input
// for time related functions return value is in milliseconds stored as 64-bit
// signed integer

bool scan_down(SDL_Scancode scancode);
int scan_count(SDL_Scancode scancode);

i64 scan_time(SDL_Scancode scancode);
i64 scan_deltat(SDL_Scancode scancode);

bool key_down(SDL_Keycode key);
int key_count(SDL_Keycode key);

i64 key_time(SDL_Keycode key);
i64 scan_deltat(SDL_Keycode key);

#endif // EVENTS_H
