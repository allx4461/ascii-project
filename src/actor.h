#pragma once
#include "entity.h"
#include "sprite_utils.h"
#include <vector>
#include <string>
#include "world.h"
#include "canvas.h"

class Actor : public Entity {
protected:
    int x, y, w, h;
    int v; // -1 влево, +1 вправо
    std::vector<std::string> spriteRight;
    std::vector<std::string> spriteLeft;

public:
    Actor(int x, int y, int v, const std::vector<std::string>& sprite);
    virtual ~Actor();
    virtual void move();//двинет корды в нужном направлении

    std::vector<int> getinfo();//x,y,h,w

    std::vector<std::vector<char>> getSprite() override;//в зависимости от v вернет спрайт

    void update(World& world) override;//пока только делает мув

    virtual void draw(Canvas& canvas);
};
