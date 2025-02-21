/*
 * main.c
 *
 * Platforming game ZANGORO.
 * Arguably will be the best game of all time.
 */

#include <stdlib.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "events.h"
#include "scratch/test_feature.h"

#define TITLE "ZANGORO"

#define WINDOW_W  (800)
#define WINDOW_H  (600)
#define WINDOW_FL (0)

#define INIT_FLAGS (SDL_INIT_AUDIO  | SDL_INIT_VIDEO   | SDL_INIT_JOYSTICK | \
                    SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS)

SDL_Window   *window;
SDL_Renderer *render;

void destroy_sdl(void);

/*
 * SDL_AppInit
 *
 * SDL_MAIN_USE_CALLBACKS macro aboves means I am using callbacks structure to
 * program which is good for some platforms. In this file I have this function
 * for startup, one for event handling, one for iterating the game state, and
 * finally one for shutdown (shutdown one does not really do anything).
 */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    (void) appstate;
    (void) argc;
    (void) argv;

    // initialize global state and SDL

    if (!SDL_Init(INIT_FLAGS) ||
        !(window = SDL_CreateWindow(TITLE, WINDOW_W, WINDOW_H, WINDOW_FL)) ||
        !(render = SDL_CreateRenderer(window, NULL))) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR, 
            "critical failure during startup, exiting\n"
        );
        return SDL_APP_FAILURE;
    }

    // cleanup window, renderer, and subsystems at exit

    atexit(destroy_sdl);

    // use to test random stuff being implemented

    test_feature(); // scratch/test_feature.c

    return SDL_APP_CONTINUE;
}

void destroy_sdl(void) {
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    (void) appstate;

    handle_event(event);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    (void) appstate;

    // get_should_quit() is defined in events.c and indicates whether or not
    // some event dictated the app should quit

    if (get_should_quit()) return SDL_APP_SUCCESS;

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    (void) appstate;
    (void) result;
}
