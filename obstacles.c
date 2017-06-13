#include "obstacles.h"
#include "util.h"

void initObstacles(SDL_Renderer* renderer) {
    loadTextures(renderer);
}

void drawObstacles() {

}

bool loadTextures(SDL_Renderer* renderer) {
    if(!loadTexture(renderer, &rockTexture, "rock.png")) {
        printf("Couldn't load texture for rock\n");
        return false;
    }

    if(!loadTexture(renderer, &rockTexture, "tree.png")) {
        printf("Couldn't load texture for tree\n");
        return false;
    }

    return true;
}
