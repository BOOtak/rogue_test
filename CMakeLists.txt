cmake_minimum_required(VERSION 3.11)
project(roguetest)

set(CMAKE_CXX_STANDARD 17)

include(cmake/spdlog.cmake)

add_subdirectory("src/lib/ECS")
add_subdirectory("src/game")
