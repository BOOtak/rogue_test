add_executable(rougetest
        main.cpp
        entities/Player.cpp
        entities/Mob.cpp
        events/PingEvent.h
        systems/PingSystem.cpp
        systems/InputSystem.cpp
        systems/InputSystem.h
        events/InputEvent.h
        events/PlayerMoveEvent.h
        systems/MoveSystem.cpp
        systems/MoveSystem.h)

target_link_libraries(rougetest PUBLIC ecs)
