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
    svr.Get("/add_fish1", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(world_mutex);
        auto new_fish = std::make_unique<fish1>(world.width(), world.height());
        world.addEntity(std::move(new_fish));
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("Рыбка добавлена!", "text/plain; charset=utf-8");
    });
    svr.Get("/add_fish2", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(world_mutex);
        auto new_fish = std::make_unique<fish2>(world.width(), world.height());
        world.addEntity(std::move(new_fish));
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("Рыбка добавлена!", "text/plain; charset=utf-8");
    });
    svr.Get("/add_fish3", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(world_mutex);
        auto new_fish = std::make_unique<fish3>(world.width(), world.height());
        world.addEntity(std::move(new_fish));
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("Рыбка добавлена!", "text/plain; charset=utf-8");
    });
    svr.Get("/add_fish4", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(world_mutex);
        auto new_fish = std::make_unique<fish4>(world.width(), world.height());
        world.addEntity(std::move(new_fish));
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_content("Рыбка добавлена!", "text/plain; charset=utf-8");
    });
    svr.Get("/add_fish5", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(world_mutex);
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