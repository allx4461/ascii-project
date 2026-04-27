#include "world.h"
#include "canvas.h"
#include "entity.h"
#include <vector>

World::World(float width, float height): w_width(width), w_height(height){}

void World::update(){
    for (auto& entity:w_entities){
        entity->update(*this); //обновляем состояние сущности(координаты, направление)
    }
}

void World::render(Canvas& canvas){
    canvas.drawBorder();

    for (auto& entity:w_entities){
        entity->draw(canvas); // отрисовываем каждую сущность
    }
}

void World::addEntity(std::unique_ptr<Entity> entity){   
    w_entities.push_back(std::move(entity)); //добавляем в массив

}


void World::removeEntity(Entity* entity){
    for (auto i=w_entities.begin(); i!=w_entities.end(); ++i){
        if (i->get() == entity){
            w_entities.erase(i); //удаляем сущность из массива сущностей
            break;
        }
    }
}

void World::clear(){
    w_entities.clear(); //чистим массив
}

int World::width() const{
    return w_width;
}

int World::height() const{
    return w_height;
}

bool World::inside(int x, int y, int h, int w){
    return (x>=0 && x+h<=w_width) && (y>=0 && y+w<= w_height);//проверка не вывалилась ли рыбка за аквариум
}

int World::size(){
    return w_entities.size();
}
