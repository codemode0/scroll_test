#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rally.h"
#include "truck.h"
#include "background.h"
#include "obstacles.h"
#include "gametimer.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 1000;
const int SCREEN_TICK_PER_FRAME = 1000/SCREEN_FPS;

SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Renderer* renderer;

bool isDone = false;




bool init();
void processEvents();
void shutdown();


int main() {
    if(!init()) {
        return -1;
    }

    initBackground(renderer);
    initTruck(renderer);
    initObstacles(renderer);

    int countedFrames = 0;
    struct GameTimer fpsTimer;
    struct GameTimer capTimer;
    struct GameTimer elapsedTimer;
    initTimer(&fpsTimer);
    initTimer(&capTimer);
    initTimer(&elapsedTimer);
    startTimer(&fpsTimer);

    while(!isDone) {
        startTimer(&capTimer);
        processEvents();
        currentKeyStates = SDL_GetKeyboardState( NULL );

        float avgFPS = countedFrames / (getTicks(&fpsTimer) / 1000.f);
        if(avgFPS > 2000000) {
            avgFPS = 0;
        }

        if( currentKeyStates[ SDL_SCANCODE_GRAVE ] ) {
            printf("FPS: %f\n", avgFPS);
        }



        float timeStep = getTicks(&elapsedTimer) / 1000.f;
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( renderer );
		drawBackground(timeStep);
        drawTruck(timeStep);
        drawObstacles();

        startTimer(&elapsedTimer);

        SDL_RenderPresent(renderer);
        countedFrames++;

        int frameTicks = getTicks(&capTimer);
        if(frameTicks < SCREEN_TICK_PER_FRAME) {
            SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
        }
    }

    destroyBackground();
    destroyTruck();
    shutdown();
    return 0;

}

void processEvents() {
    SDL_Event event;

    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            isDone = true;
        }
    }
}

void shutdown() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

bool init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL init fail: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if(!window) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        printf("Could not init SDL_Image, error: %s", IMG_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if(!renderer) {
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

    return true;
}
