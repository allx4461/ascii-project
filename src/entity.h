#pragma once
#include <string>
#include <vector>
#include "world.h"
#include "canvas.h"

class World;
class Entity{
public:
    virtual ~Entity() =default;//киллить наследников
    virtual std::vector<int> getinfo()=0;//возвращает вектор из полей
    virtual std::vector<std::vector<char>> getSprite() = 0;//возвращает спрайт
    virtual void update(World& world)=0;
    virtual void draw(Canvas& canvas)=0;};
