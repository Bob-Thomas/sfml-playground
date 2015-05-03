//
// Created by bob on 1-5-2015.
//

#ifndef CATRPG_GAMESTATE_H
#define CATRPG_GAMESTATE_H


#include <src/stateArchitecture/state.h>
#include <src/scene/world.h>

class GameState : public State {
public:
    GameState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

private:
    World mWorld;
    Player& mPlayer;
};


#endif //CATRPG_GAMESTATE_H
