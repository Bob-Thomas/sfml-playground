//
// Created by bob on 3-5-2015.
//

#ifndef CATRPG_GAMEOVERSTATE_H
#define CATRPG_GAMEOVERSTATE_H

#include <src/stateArchitecture/state.h>
#include <src/gui/container.h>
#include <src/stateArchitecture/stateStack.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameOverState : public State
{
public:
    GameOverState(StateStack& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);


private:
    sf::Text			mGameOverText;
    sf::Time			mElapsedTime;
};

#endif //CATRPG_GAMEOVERSTATE_H
