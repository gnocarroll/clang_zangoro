#include "events.h"

#include <stdbool.h>

#include <SDL3/SDL.h>

#include "mynumdef.h"

static bool should_quit = false;

// data structures to store information on user input

static bool key_states[SDL_SCANCODE_COUNT];
static int  key_counts[SDL_SCANCODE_COUNT];
static i64  key_timestamps[SDL_SCANCODE_COUNT]; 

// access information about which key scancodes were input

bool scan_down (SDL_Scancode scancode) { return key_states[scancode]; }
int  scan_count(SDL_Scancode scancode) { return key_counts[scancode]; }

i64 scan_time(SDL_Scancode scancode) {
    return key_timestamps[scancode] / 1000; // to ms
}
i64 scan_deltat(SDL_Scancode scancode) { // how long ago
    return (SDL_GetTicksNS() - key_timestamps[scancode]) / 1000;
}

// access information about which keycodes were input, information is stored
// using scancode so all of these just apply a conversion

bool key_down(SDL_Keycode key) {
    return scan_down(SDL_GetScancodeFromKey(key, NULL));
}
int key_count(SDL_Keycode key) {
    return scan_count(SDL_GetScancodeFromKey(key, NULL));
}

i64 key_time(SDL_Keycode key) {
    return scan_time(SDL_GetScancodeFromKey(key, NULL));
}
i64 key_deltat(SDL_Keycode key) {
    return scan_deltat(SDL_GetScancodeFromKey(key, NULL));
}

// return static var indicating if should quit app

bool get_should_quit() {
    return should_quit;
}

#define HANDLER_FUNC(x, event) static void handle_##x(const SDL_Event* event)

static void handle_should_quit(const SDL_Event *event) {
    (void) event;
    should_quit = true;
}

static void handle_SDL_EVENT_QUIT(const SDL_Event* event) {
    handle_should_quit(event);
}

static void handle_SDL_EVENT_WINDOW_DESTROYED(const SDL_Event* event) {
    handle_should_quit(event);
}

static void handle_SDL_EVENT_WINDOW_CLOSE_REQUESTED(const SDL_Event* event) {
    handle_should_quit(event);
}

// Keyboard event - key press or release

static void handle_keyboard_event(const SDL_Event *event) {
    const SDL_KeyboardEvent *key = &event->key;

    if (key->repeat) return; // ignore repeats

    key_states[key->scancode] = key->down;
    
    if (key->down) {
        key_counts[key->scancode]++;
        key_timestamps[key->scancode] = key->timestamp; // in nanoseconds
    }
}

HANDLER_FUNC(SDL_EVENT_KEY_DOWN, event) {
    handle_keyboard_event(event);
}

HANDLER_FUNC(SDL_EVENT_KEY_UP, event) {
    handle_keyboard_event(event);
}

#define EVENT_CASE(x, event) case x: handle_##x(event); break

void handle_event(const SDL_Event *event) {
    switch (event->type) {
    EVENT_CASE(SDL_EVENT_QUIT, event);
    EVENT_CASE(SDL_EVENT_WINDOW_CLOSE_REQUESTED, event);
    EVENT_CASE(SDL_EVENT_WINDOW_DESTROYED, event);
    EVENT_CASE(SDL_EVENT_KEY_DOWN, event);
    EVENT_CASE(SDL_EVENT_KEY_UP, event);
    default:
        break;
    }
}
