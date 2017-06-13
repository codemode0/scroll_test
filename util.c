#include "util.h"

bool loadTexture(SDL_Renderer* renderer, SDL_Texture** texture, const char* path) {
	SDL_Surface* loadedSurface = IMG_Load(path);
	if(!loadedSurface) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	} else {
		//Create texture from surface pixels
        *texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if(!texture) {
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		}
		SDL_FreeSurface( loadedSurface );
	}

    return true;
}
