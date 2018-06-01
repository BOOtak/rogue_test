cmake_minimum_required(VERSION 3.11)
project(rougetest)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("src/lib/ECS")
add_subdirectory("src/game")
