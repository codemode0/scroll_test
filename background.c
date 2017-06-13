#include "background.h"
#include "util.h"

void drawBackground(float elapsedTime) {
    background->offsetY -= 120 * elapsedTime;
    if(background->sourceRect.y < 0) {
        background->offsetY = 600;
    }

    background->sourceRect.y = (int) background->offsetY;

    SDL_RenderCopy(background->renderer, background->texture, &background->sourceRect, NULL);
}

bool initBackground(SDL_Renderer* renderer) {
    background = malloc(sizeof(struct Background));

    if(!background) {
        printf("Couldn't get memory for background structure.\n");
        return false;
    }
    background->renderer = renderer;

    background->sourceRect.x = 0;
    background->sourceRect.y = 600;
    background->sourceRect.w = 800;
    background->sourceRect.h = 600;

    background->offsetY = 600;

    if(!loadTexture(renderer, &background->texture, "road.png")) {
        printf("Couldn't load road texture\n");
        return false;
    }

    return true;
}

void destroyBackground() {
    SDL_DestroyTexture(background->texture);
    free(background);
}
