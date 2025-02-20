#include "clock.h"

#include <SDL3/SDL.h>

#include "mynumdef.h"

static float old_time;
static float deltat;

void start_clock() {
    old_time = get_time();
}

float get_time() {
    return SDL_GetTicks() / 1000;
}

float get_deltat() {
    return deltat;
}

void update_deltat() {
    float new_time = get_time();

    deltat = new_time - old_time;

    old_time = new_time;
}
