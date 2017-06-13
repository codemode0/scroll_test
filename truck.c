#include "truck.h"
#include "util.h"


bool truckSteerLeft(float elapsedTime) {
    truck->steerAmount -= 0.02f;
    if(truck->steerAmount < -1.0f) {
        truck->steerAmount = -1.0f;
    }

    truck->xPos+=truck->XYVelocity*elapsedTime*truck->steerAmount;

    truck->angle = 10.0 * truck->steerAmount;
    if(truck->xPos < 0) {
        truck->xPos=0;
        return false;
    }
    return true;
}

bool truckSteerRight(float elapsedTime) {
    truck->steerAmount += 0.02f;
    if(truck->steerAmount > 1.0f) {
        truck->steerAmount = 1.0f;
    }
    truck->xPos+=truck->XYVelocity*elapsedTime*truck->steerAmount;
    truck->angle = 10.0 * truck->steerAmount;
    if(truck->xPos > 800 - truck->dest.w) {
        truck->xPos = 800 - truck->dest.w;
        return false;
    }
    return true;
}

bool truckSteerStraight(float elapsedTime) {
    if(truck->steerAmount < 0) {
        truck->steerAmount += 0.02f;
        truck->xPos+=truck->XYVelocity*elapsedTime*truck->steerAmount;
    } else if(truck->steerAmount > 0) {
        truck->steerAmount -= 0.02f;
        truck->xPos+=truck->XYVelocity*elapsedTime*truck->steerAmount;
    }

    truck->angle = 10.0 * truck->steerAmount;
    return true;
}

void drawTruck(float elapsedTime) {
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] ) {
        truckSteerLeft(elapsedTime);
    }
    else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ) {
        truckSteerRight(elapsedTime);
    } else {
        truckSteerStraight(elapsedTime);
    }
    truck->dest.x = (int)truck->xPos;
    truck->dest.y = (int)truck->yPos;
    // SDL_RenderCopy(truck->renderer, truck->texture, NULL, &truck->dest);
    SDL_RenderCopyEx(truck->renderer, truck->texture, NULL, &truck->dest, truck->angle, NULL, SDL_FLIP_NONE);
}

bool initTruck(SDL_Renderer* renderer) {
    truck = malloc(sizeof(struct Truck));

    if(!truck) {
        printf("Couldn't get memory for truck structure.\n");
        return false;
    }

    truck->dest.x = 380;
    truck->dest.y = 510;
    truck->dest.w = 40;
    truck->dest.h = 86;

    truck->angle = 0.0f;
    truck->steerAmount = 0.0f;
    truck->XYVelocity = 200;
    truck->xPos = 380;
    truck->yPos=510;

    truck->renderer = renderer;

    if(!loadTexture(renderer, &(truck->texture), "car.png")) {
        printf("Couldn't load texture for truck\n");
        return false;
    }

    printf("Truck init complete\n");

    return true;
}

void destroyTruck() {
    SDL_DestroyTexture(truck->texture);
    free(truck);
}
