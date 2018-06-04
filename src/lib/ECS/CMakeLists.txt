cmake_minimum_required(VERSION 3.11)
project(rougetest)

set(CMAKE_CXX_STANDARD 17)

add_library(ecs STATIC
        Entity.cpp
        EntityManager.cpp
        Event.cpp
        EventBus.cpp
        Property.cpp
        System.cpp
        World.cpp
        include/Entity.h
        include/EntityManager.h
        include/Event.h
        include/EventBus.h
        include/Property.h
        include/System.h
        include/World.h
        EventDelegate.cpp
        include/EventDelegate.h
        include/BaseEventDelegate.h include/EventListener.h)

target_include_directories(ecs PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
