include(FindCurses)
find_package(Curses REQUIRED)

add_executable(roguetest
        main.cpp
        entities/Camera.cpp
        entities/Player.cpp
        entities/Mob.cpp
        entities/Wall.cpp
        events/InputEvent.h
        events/MoveEvent.h
        events/PingEvent.h
        events/PlayerMoveEvent.h
        properties/CharTexture.h
        properties/Focus.h
        properties/RigidBody.h
        systems/CameraSystem.cpp
        systems/CameraSystem.h
        systems/CursesRawInputSystem.cpp
        systems/CursesRawInputSystem.h
        systems/InputSystem.cpp
        systems/InputSystem.h
        systems/MoveSystem.cpp
        systems/MoveSystem.h
        systems/PlayerMoveSystem.cpp
        systems/PlayerMoveSystem.h
        systems/RenderSystem.cpp
        systems/RenderSystem.h
        utils/logging.h
        utils/LogWrapper.cpp
        utils/LogWrapper.h
        utils/Vector2.cpp
        utils/Vector2.h
        )

target_include_directories(roguetest PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(roguetest PUBLIC ecs ${CURSES_LIBRARIES})
target_link_libraries(roguetest PUBLIC spdlog::spdlog)
