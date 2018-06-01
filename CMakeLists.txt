cmake_minimum_required(VERSION 3.11)
project(rougetest)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/ECS")

add_executable(rougetest
        src/main.cpp
        src/commands/MoveCommand.cpp
        src/entities/Player.cpp
        src/entities/Mob.cpp
        src/events/PingEvent.h
        src/systems/PingSystem.cpp
        )

target_link_libraries(rougetest PUBLIC ecs)
