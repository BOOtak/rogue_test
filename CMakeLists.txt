cmake_minimum_required(VERSION 3.11)
project(rougetest)

set(CMAKE_CXX_STANDARD 17)

add_executable(rougetest
        src/main.cpp
        src/ECS/Entity.cpp
        src/ECS/Entity.h
        src/ECS/Property.cpp
        src/ECS/Property.h
        src/ECS/Command.cpp
        src/ECS/Command.h
        src/commands/MoveCommand.cpp
        src/commands/MoveCommand.h
        src/properties/Position.h
        )
