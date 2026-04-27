#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <cstdint>
#include <string>

enum class Color:std::uint8_t {Default, Blue, Green, Yellow, LiteBlue};

struct Cell{
    char ch = ' ';
    Color color = Color::Default;
};

class Canvas{
private:
    int c_width; 
    int c_height; 
    std::vector<std::vector<Cell>> world_matrix;

public:
    Canvas(int width, int height);
    ~Canvas()= default;

    void clear(char fill = ' ', Color col = Color::Default);
    void addSprite(const std::vector<std::vector<char>>& entity, int x, int y, Color color = Color::Default);
    void drawBorder();
    void set(int x, int y, char ch, Color color = Color::Default);
    void present();
    std::string getFrameAsString();
};
#endif //CANVAS_H