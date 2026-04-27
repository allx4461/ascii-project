#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include "entity.h"
#include "canvas.h"
class Entity;
class World{
public:
    World(float worldWidth, float worldHeight);
    ~World()=default;

    void update();//обновляет состояние
    void render(Canvas& canvas);

    void addEntity(std::unique_ptr<Entity> entity);
    void removeEntity(Entity* entity);
    void clear();

    int width() const;
    int height() const;
    bool inside(int x, int y, int h, int w); 
    int size();

private:
    int w_width = 0;
    int w_height = 0;

    std::vector<std::unique_ptr<Entity>> w_entities;
};

#endif //WORLD_H