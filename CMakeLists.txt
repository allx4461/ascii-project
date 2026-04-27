cmake_minimum_required(VERSION 3.10)
project(Aquarium)

set(CMAKE_CXX_STANDARD 17)

# Собираем все .cpp файлы в папке src
file(GLOB SOURCES "src/*.cpp")

add_executable(aquarium_service ${SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(aquarium_service Threads::Threads)