#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdbool.h>

struct Background {
    SDL_Texture* texture;
    SDL_Rect sourceRect;
    SDL_Renderer* renderer;

    float offsetY;
};

static struct Background* background;

void drawBackground(float elapsedTime);
void destroyBackground();
bool initBackground(SDL_Renderer*);
