//
// Created by kirill on 24.05.18.
//

#ifndef ROUGETEST_MOVECOMMAND_H
#define ROUGETEST_MOVECOMMAND_H


#include "ECS/Command.h"
#include "ECS/Entity.h"

class MoveCommand : public Command {
public:
    MoveCommand(int x, int y, Entity *entity);

    void execute() override;

private:
    int x;
    int y;
    Entity* entity;
};


#endif //ROUGETEST_MOVECOMMAND_H
