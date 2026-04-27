#include "canvas.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

Canvas::Canvas(int width, int height): c_width(width), c_height(height), world_matrix(height, std::vector<Cell>(width, Cell{' ', Color::Default})){}

static std::string patternToWidth(const std::string& pattern, int width){
    if (pattern.empty() || width<pattern.size()) return std::string(width, ' ');
    std::string out;
    out.reserve(width);
    while ((int)out.size()<width) out += pattern;
    out.resize(width);
    return out;
}

static std::string colorFor(Color col) {
    switch (col) {
        case Color::Blue:     return "#00d5ff"; // Cyan/Blue
        case Color::Yellow:   return "#ffd700"; // Gold
        case Color::Green:    return "#40ff40"; // Green
        case Color::LiteBlue: return "#aaffff"; // Bright Cyan
        default:              return "#ffffff"; // White
    }
}
void Canvas::set(int x, int y, char ch, Color color){
    if (x<0 || x>=c_width || y<0 || y>=c_height) return;
    world_matrix[y][x] = Cell{ch, color};
}

void Canvas::drawBorder(){
    if (c_width<2 || c_height<10)return;

    const std::string foam = "~~~~~._.~~))~~~.,.~~~~~~~~.,.";
    const std::string sand = ".  *  . , .  *  -   ` .  ' ,";
    const std::string wave = "/\\/\\";

    std::string foamLine = patternToWidth(foam, c_width);
    std::string sandLine = patternToWidth(sand, c_width);
    std::string waveLine = patternToWidth(wave, c_width);
    for (int x=0; x<c_width; ++x){
        set(x, 0, waveLine[x], Color::Blue);
        if (foamLine[x]!=')')set(x, c_height-2, foamLine[x], Color::Yellow);
        else set(x, c_height-2, foamLine[x], Color::Green);
        set(x, c_height-1, sandLine[x], Color::Default);
        for (int j=0; j<=4; ++j){
            if (c_height-2-j<0) break;

            if ((world_matrix[c_height-2-j][x]).ch==')'){
                set(x-1, c_height-3-j, '(', Color::Green);
            }else if((world_matrix[c_height-2-j][x-1]).ch=='('){
                set(x, c_height-3-j, ')', Color::Green);
            }
        }
    }
}

void Canvas::present(){
    for (int y=0; y<c_height; ++y){
        for (int x=0; x<c_width; ++x){
            const Cell& el =  world_matrix[y][x];
            std::cout << colorFor(el.color) << el.ch;
        }
        std::cout << std::endl;
    }
}

void Canvas::clear(char fill, Color col){
    for (int y=0; y<c_height; ++y){
        for (int x=0; x<c_width; ++x){
            world_matrix[y][x]= Cell{fill, col};
        }
    }
}

void Canvas::addSprite(const std::vector<std::vector<char>>& entity, int x, int y, Color color){
    for (int iy=0; iy<entity.size(); ++iy){
        for (int ix=0; ix<entity[iy].size(); ++ix){
            if (entity[iy][ix] == ' '){continue;}
            else if(entity[iy][ix]=='%'){set(x+ix ,y+iy, ' ', color);}
            else{set(x+ix ,y+iy, entity[iy][ix], color);}
        }
    }
}

std::string Canvas::getFrameAsString() {
    std::stringstream ss;
    for (int y = 0; y < c_height; ++y) {
        for (int x = 0; x < c_width; ++x) {
            const Cell& el = world_matrix[y][x];
            
            // Оборачиваем каждый символ в span с цветом
            ss << "<span style='color:" << colorFor(el.color) << "'>" 
               << el.ch 
               << "</span>";
        }
        ss << "\n";
    }
    return ss.str();
}