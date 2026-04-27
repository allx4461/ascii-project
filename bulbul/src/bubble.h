#pragma once
#include "actor.h"

class Bubble : public Actor {
public:
    Bubble(int worldWidth, int worldHeight);
    void move() override; };
