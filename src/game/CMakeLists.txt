include(FindCurses)
find_package(Curses REQUIRED)

add_executable(roguetest
        main.cpp
        entities/Player.cpp
        entities/Mob.cpp
        entities/Wall.cpp
        events/MoveEvent.h
        events/PingEvent.h
        events/PlayerMoveEvent.h
        systems/InputSystem.cpp
        systems/InputSystem.h
        events/InputEvent.h
        systems/PlayerMoveSystem.cpp
        systems/PlayerMoveSystem.h
        systems/RenderSystem.cpp
        systems/RenderSystem.h
        properties/CharTexture.h
        properties/RigidBody.h
        systems/CursesRawInputSystem.cpp
        systems/CursesRawInputSystem.h
        systems/MoveSystem.cpp
        systems/MoveSystem.h
        utils/Vector2.cpp
        utils/Vector2.h
        )

target_include_directories(roguetest PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(roguetest PUBLIC ecs ${CURSES_LIBRARIES})
