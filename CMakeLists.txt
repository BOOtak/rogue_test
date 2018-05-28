cmake_minimum_required(VERSION 3.11)
project(rougetest)

set(CMAKE_CXX_STANDARD 17)

add_executable(rougetest main.cpp ECS/Entity.cpp ECS/Entity.h ECS/Property.cpp ECS/Property.h ECS/Command.cpp ECS/Command.h MoveCommand.cpp MoveCommand.h properties/Position.h)