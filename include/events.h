#ifndef EVENTS_H
#define EVENTS_H

#include <stdbool.h>

#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>

union SDL_Event;

void handle_event(const union SDL_Event* event);

// should_quit will indicate if app should shut down

bool get_should_quit();

// functions to get information on keyboard input
// for time-related functions valued is in seconds stored as a float

bool scan_down(SDL_Scancode scancode);
int scan_count(SDL_Scancode scancode);

float scan_time(SDL_Scancode scancode);
float scan_deltat(SDL_Scancode scancode);

bool key_down(SDL_Keycode key);
int key_count(SDL_Keycode key);

float key_time(SDL_Keycode key);
float key_deltat(SDL_Keycode key);

#endif // EVENTS_H
