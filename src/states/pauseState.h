//
// Created by bob on 1-5-2015.
//

#ifndef CATRPG_PAUSESTATE_H
#define CATRPG_PAUSESTATE_H

#include <src/stateArchitecture/state.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class PauseState : public State
{
public:
    PauseState(StateStack& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);


private:
    sf::Sprite			mBackgroundSprite;
    sf::Text			mPausedText;
    sf::Text			mInstructionText;
};



#endif //CATRPG_PAUSESTATE_H
