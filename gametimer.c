#include "gametimer.h"

void initTimer(struct GameTimer* t) {
    t->startTicks = 0;
    t->pauseTicks = 0;
    t->isPaused = false;
    t->isStarted = false;
}

void startTimer(struct GameTimer* t) {
    t->isStarted = true;
    t->isPaused = false;

    t->startTicks = SDL_GetTicks();
    t->pauseTicks = 0;
}

void stopTimer(struct GameTimer* t) {
    t->isStarted = false;
    t->isPaused = false;

    t->startTicks = 0;
    t->pauseTicks = 0;
}

void pauseTimer(struct GameTimer* t) {
    if(t->isStarted && !t->isPaused) {
        t->isPaused = true;

        t->pauseTicks = SDL_GetTicks() - t->startTicks;
        t->startTicks = 0;
    }
}

void unpauseTimer(struct GameTimer* t) {
    if(t->isStarted && t->isPaused) {
        t->isPaused = false;
        t->startTicks = SDL_GetTicks() - t->pauseTicks;

        t->pauseTicks = 0;
    }
}

bool isTimerStarted(struct GameTimer* t) {
    return t->isStarted;
}

bool isTimerPaused(struct GameTimer* t) {
    return t->isPaused && t->isStarted;
}

unsigned long getTicks(struct GameTimer* t) {
    unsigned long time = 0;

    if(t->isStarted) {
        if(t->isPaused) {
            time = t->pauseTicks;
        } else {
            time = SDL_GetTicks() - t->startTicks;
        }
    }

    return time;
}
