#include <SDL.h>


#include <stdbool.h>



const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


SDL_Window* window;
SDL_Renderer* renderer;

const Uint8* currentKeyStates;

bool isDone = false;

bool init();
void processEvents();
void shutdown();


int main() {
    if(!init()) {
        return -1;
    }


    while(!isDone) {

        processEvents();
        currentKeyStates = SDL_GetKeyboardState( NULL );


        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear( renderer );
	    SDL_RenderPresent(renderer);

    }


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


    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if(!renderer) {
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

    return true;
}
