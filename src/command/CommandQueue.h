//
// Created by bob on 30-4-2015.
//

#ifndef CATRPG_COMMANDQUEUE_H
#define CATRPG_COMMANDQUEUE_H

#include <queue>
#include "command.h"

class CommandQueue
{
    public:
        void push(const Command& command);
        Command pop();
        bool isEmpty() const;
    private:
        std::queue<Command> mQueue;
};
#endif //CATRPG_COMMANDQUEUE_H
