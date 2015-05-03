//
// Created by bob on 1-5-2015.
//

#ifndef CATRPG_TITLESTATE_H
#define CATRPG_TITLESTATE_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <src/stateArchitecture/state.h>

class TitleState : public State {
public:
    TitleState(StateStack& stack, Context context);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

private:
    sf::Sprite mBackgroundSprite;
    sf::Text mText;

    bool mShowText;
    sf::Time mTextEffectTime;
};


#endif //CATRPG_TITLESTATE_H
