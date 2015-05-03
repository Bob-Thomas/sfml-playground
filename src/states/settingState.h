//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_SETTINGSTATE_H
#define CATRPG_SETTINGSTATE_H

#include <src/stateArchitecture/State.h>
#include <src/player.h>
#include <src/gui/container.h>
#include <src/gui/button.h>
#include <src/gui/label.h>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingState : public State {
public:
    SettingState(StateStack &stack, Context context);

    virtual void draw();

    virtual bool update(sf::Time dt);

    virtual bool handleEvent(const sf::Event &event);


private:
    void updateLabels();

    void addButtonLabel(Player::Action action, float y, const std::string &text, Context context);


private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
    std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
    std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};

#endif //CATRPG_SETTINGSTATE_H
