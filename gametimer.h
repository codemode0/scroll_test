#include <SDL.h>
#include <stdbool.h>

struct GameTimer {
    unsigned int startTicks;
    unsigned int pauseTicks;
    bool isStarted;
    bool isPaused;
};

void initTimer(struct GameTimer*);

void startTimer(struct GameTimer*);
void stopTimer(struct GameTimer*);

void pauseTimer(struct GameTimer*);
void unpauseTimer(struct GameTimer*);

bool isTimerStarted(struct GameTimer*);
bool isTimerPaused(struct GameTimer*);
unsigned long getTicks(struct GameTimer*);
