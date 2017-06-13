#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>

#include "rally.h"

struct Truck {
    SDL_Texture* texture;
    SDL_Rect dest;
    SDL_Renderer* renderer;
    float angle;
    int XYVelocity;
    float xPos;
    float yPos;

    float steerAmount;
};

static struct Truck* truck;

bool initTruck(SDL_Renderer*);
void destroyTruck();

bool truckSteerLeft(float elapsedTime);
bool truckSteerRight(float elapsedTime);
bool truckSteerStraight(float elapsedTime);

void drawTruck(float elapsedTime);
