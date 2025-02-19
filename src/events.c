#include "events.h"

#include <stdbool.h>

#include <SDL3/SDL.h>

static bool should_quit = false;

bool get_should_quit() {
    return should_quit;
}

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

#define EVENT_CASE(x, event) case x: handle_##x(event); break

void handle_event(const SDL_Event *event) {
    switch (event->type) {
    EVENT_CASE(SDL_EVENT_QUIT, event);
    EVENT_CASE(SDL_EVENT_WINDOW_CLOSE_REQUESTED, event);
    EVENT_CASE(SDL_EVENT_WINDOW_DESTROYED, event);
    }
}
