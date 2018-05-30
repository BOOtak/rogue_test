cmake_minimum_required(VERSION 3.11)
project(rougetest)

set(CMAKE_CXX_STANDARD 17)

add_executable(rougetest
        src/main.cpp
        src/ECS/Entity.cpp
        src/ECS/Property.cpp
        src/ECS/Command.cpp
        src/commands/MoveCommand.cpp
        src/ECS/World.cpp
        src/ECS/EntityManager.cpp
        src/entities/Player.cpp
        src/entities/Mob.cpp
        )
