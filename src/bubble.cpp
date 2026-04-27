#include "bubble.h"
#include <cstdlib>

Bubble::Bubble(int worldWidth, int worldHeight)
    : Actor(
        rand() % worldWidth,   // x
        rand() % worldHeight,  // y
        0,                     // v — по x не двигается
        { "o"}
    )
{}

void Bubble::move() {--y;}