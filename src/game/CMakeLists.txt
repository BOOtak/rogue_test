add_executable(rougetest
        main.cpp
        commands/MoveCommand.cpp
        entities/Player.cpp
        entities/Mob.cpp
        events/PingEvent.h
        systems/PingSystem.cpp
        )

target_link_libraries(rougetest PUBLIC ecs)
