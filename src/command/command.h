//
// Created by bob on 30-4-2015.
//

#ifndef CATRPG_COMMAND_H
#define CATRPG_COMMAND_H

#include <SFML/System/Time.hpp>
#include <functional>
#include <cassert>
#include <src/objects/categories.h>


class SceneNode;

struct Command {
    Command();

    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&node) != nullptr);

        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(node), dt);
    };
}


#endif //CATRPG_COMMAND_H
