cmake_minimum_required(VERSION 3.24)
project(linkDouble)

set(CMAKE_CXX_STANDARD 17)

add_executable(linkDouble main.cpp Node.h LinkedList.cpp LinkedList.h Dish.cpp Dish.h Videogame.h Videogame.cpp)
