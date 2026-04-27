#pragma once
#include "actor.h"
#include "sprite_utils.h"
#include <vector>
#include <string>
#include <cstdlib>


class fish1: public Actor{
public:
    fish1(int worldWidth, int worldHeight); };

class fish2: public Actor{
public:
    fish2(int worldWidth, int worldHeight); };

class fish3: public Actor{
public:
    fish3(int worldWidth, int worldHeight); };

class fish4: public Actor{
public:
    fish4(int worldWidth, int worldHeight); };

class fish5: public Actor{
public:
    fish5(int worldWidth, int worldHeight); };

class fish6: public Actor{
public:
    fish6(int worldWidth, int worldHeight); };

class fish7: public Actor{
public:
    fish7(int worldWidth, int worldHeight); };


    
class weed1: public Actor{
public:
    weed1(int worldWidth, int worldHeight); 
    void move() override;
    void draw(Canvas& canvas) override;
};
