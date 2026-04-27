//https://en.cppreference.com/w/cpp/preprocessor/impl.html
#include "actor.h"

Actor::Actor(int x, int y, int v, const std::vector<std::string>& sprite)
    : x(x), y(y), v(v), spriteRight(sprite)//инициализация полей - поле(параметр конструктора)
{                      
    spriteLeft = SpriteUtils::flipHorizontally(spriteRight);

    auto [ww, hh] = SpriteUtils::getSize(spriteRight); //std::pair<int,int> вместо first,second
    w = ww;//^^ https://en.cppreference.com/w/cpp/utility/pair.html
    h = hh;
}

std::vector<int> Actor::getinfo() {return {x, y, w, h, v};}

void Actor::move(){x += v;}

std::vector<std::vector<char>> Actor::getSprite() {
    const auto& src = (v >= 0 ? spriteRight : spriteLeft);  // тернарный оператор эээ
    std::vector<std::vector<char>> res;  
    for (const auto& row : src) {
        std::vector<char> rowData(row.begin(), row.end());  // преобразуем строку в вектор символов
        res.push_back(rowData);}
    return res;  
}


void Actor::update(World& world){
    if (!(world.inside(getinfo()[0]+1,getinfo()[1], getinfo()[2],getinfo()[3]))){
        v=-v;}
    move();
    }

void Actor::draw(Canvas& canvas){ 
    std::vector<std::vector<char>> sprite = getSprite(); 
    int x = this->x;
    int y = this->y; 
    canvas.addSprite(sprite,x,y,Color::LiteBlue);
}
Actor::~Actor() {}
