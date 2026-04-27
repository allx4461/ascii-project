#include <thread>
#include <chrono>
#include <mutex>
#include "httplib.h"
#include "world.h"
#include "canvas.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime> 
#include "fishes.h"
#include "world.h"
#include "canvas.h"
#include "sprite_utils.h"
#include "entity.h"
#include "bubble.h"


// Мьютекс нужен, чтобы сервер не пытался прочитать кадр 
// в тот самый момент, когда мир обновляет положение рыбок
std::mutex world_mutex;


std::string chooseEntity(){
    std::string f;
    bool flag_s = true;
    std::cout << "choose from these:" << std::endl;
    std::cout << "small shark -1 | jellyfish -2 | fish -3 | small fish -4 | fishes -5 | seahorse -6 | seaweed -7 | 42" << std::endl;
    std::getline(std::cin, f);
    while (flag_s){      
        if (f=="1" || f=="2" || f=="3" || f=="4" || f=="5" || f=="6" || f=="7" || f=="42"){
            flag_s = false;
        }else{
            std::cout << "enter correct command pls" << std::endl;
            std::getline(std::cin, f);
        }
    }
    return f;
}
std::unique_ptr<Entity> createFish(std::string s, int width, int height){
    if (s=="1"){
        std::unique_ptr<fish1> entity = std::make_unique<fish1>(width, height);
        return entity;
    }else if(s=="4"){
        std::unique_ptr<fish2> entity = std::make_unique<fish2>(width, height);
        return entity;
    }else if(s=="3"){
        std::unique_ptr<fish3> entity = std::make_unique<fish3>(width, height);
        return entity;
    }else if(s=="5"){
        std::unique_ptr<fish4> entity = std::make_unique<fish4>(width, height);
        return entity;
    }else if(s=="2"){
        std::unique_ptr<fish5> entity = std::make_unique<fish5>(width, height);
        return entity;
    }else if(s=="6"){
        std::unique_ptr<fish6> entity = std::make_unique<fish6>(width, height);
        return entity;
    }else if(s=="42"){
        std::unique_ptr<fish7> entity = std::make_unique<fish7>(width, height);
        return entity;
    }else if(s=="7"){
        std::unique_ptr<weed1> entity = std::make_unique<weed1>(width, height);
        return entity;
    }else{
        std::cout << "net takoi entity, add basic entity" << std::endl;
        std::unique_ptr<fish2> entity = std::make_unique<fish2>(width, height);
        return entity;
    }
}

int main() {
    // 1. Создаем мир (размеры можно чуть уменьшить для веба)
    World world(120, 60); 
    
    // Добавляем начальных сущностей (как в твоем старом main)
    // world.addEntity(std::make_unique<fish1>(120, 30)); 
    Canvas canvas(world.width(), world.height());
    srand(time(0));
    auto entity1 = std::make_unique<fish1>(world.width(), world.height());
    auto entity2 = std::make_unique<fish2>(world.width(), world.height());

    world.addEntity(std::move(entity1));
    world.addEntity(std::move(entity2));
    // 2. Поток симуляции (двигаем рыбок в фоне)
    std::thread simulation_thread([&world]() {
        while (true) {
            {
                std::lock_guard<std::mutex> lock(world_mutex);
                world.update();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    });

    // 3. Настройка веб-сервера
    httplib::Server svr;

    // Эндпоинт для получения кадра
    svr.Get("/get_frame", [&](const httplib::Request&, httplib::Response& res) {
        Canvas canvas(world.width(), world.height());
        {
            std::lock_guard<std::mutex> lock(world_mutex);
            world.render(canvas);
        }
        res.set_header("Access-Control-Allow-Origin", "*"); // Чтобы браузер не ругался
        res.set_content(canvas.getFrameAsString(), "text/html");
    });
    // Эндпоинт для добавления рыбки
    svr.Get("/add_fish", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(world_mutex);
        
        // Создаем рыбку (можно даже из параметров запроса брать тип)
        auto new_fish = std::make_unique<fish5>(world.width(), world.height());
        world.addEntity(std::move(new_fish));
        
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("Рыбка добавлена!", "text/plain; charset=utf-8");
    });

    // 4. Запуск сервера
    std::cout << "Aquarium server started at http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);

    simulation_thread.join();
    return 0;
}