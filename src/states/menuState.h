//
// Created by bob on 1-5-2015.
//

#ifndef CATRPG_MENUSTATE_H
#define CATRPG_MENUSTATE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <src/stateArchitecture/state.h>
#include <src/gui/container.h>


class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);

    virtual void			draw();
    virtual bool			update(sf::Time dt);
    virtual bool			handleEvent(const sf::Event& event);


private:
    sf::Sprite				mBackgroundSprite;
    GUI::Container			mGUIContainer;
};


#endif //CATRPG_MENUSTATE_H
