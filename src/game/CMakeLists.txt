include(FindCurses)
find_package(Curses REQUIRED)



add_executable(roguetest
        main.cpp
        entities/Player.cpp
        entities/Mob.cpp
        events/PingEvent.h
        systems/InputSystem.cpp
        systems/InputSystem.h
        events/InputEvent.h
        events/PlayerMoveEvent.h
        systems/MoveSystem.cpp
        systems/MoveSystem.h
        systems/RenderSystem.cpp
        systems/RenderSystem.h
        properties/CharTexture.h)

target_include_directories(roguetest PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(roguetest PUBLIC ecs ${CURSES_LIBRARIES})
