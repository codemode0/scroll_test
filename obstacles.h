#include <SDL.h>
#include <stdbool.h>

struct Obstacles {
    int count;
    int maxCount;
};

struct Obstacle {
    SDL_Texture* texture;
    SDL_Rect dest;
    SDL_Renderer* renderer;
};

SDL_Texture* treeTexture;
SDL_Texture* rockTexture;


void initObstacles(SDL_Renderer*);
void drawObstacles();
static bool loadTextures(SDL_Renderer*);
