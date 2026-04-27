#pragma once
#include <vector>
#include <string>
#include <algorithm>

namespace SpriteUtils {
    // посчитали ширину и высоту
    inline std::pair<int,int> getSize(const std::vector<std::string>& sprite) {//инлайн-функция, чтобы не было конфликтов
        int h = (int)sprite.size();
        int w = 0;
        for (const auto& row : sprite) {if ((int)row.size() > w) w = (int)row.size();}
        return {w, h};}

    // развернули спрайт по горизонтали

    inline char mirrorChar(char c) {
        switch (c) {
            case '(': return ')';
            case ')': return '(';
            case '<': return '>';
            case '>': return '<';
            case '/': return '\\';
            case '\\': return '/';
            
            default: return c;}}

    inline std::vector<std::string> flipHorizontally(const std::vector<std::string>& sprite) {
        std::vector<std::string> result;
        result.reserve(sprite.size());
        for (const auto& row : sprite) {
            std::string flipped;
            flipped.reserve(row.size());
            for (auto it = row.rbegin(); it != row.rend(); ++it) {
                flipped.push_back(mirrorChar(*it));}
            result.push_back(flipped);}
        return result;}
    }//закрыли неймспейс