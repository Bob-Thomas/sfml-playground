//
// Created by bob on 1-5-2015.
//

#ifndef CATRPG_APPLICATION_H
#define CATRPG_APPLICATION_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>
#include <src/player.h>
#include "stateStack.h"

class Application {
public:
    Application();

    void run();


private:
    void processInput();

    void update(sf::Time dt);

    void render();

    void updateStatistics(sf::Time dt);

    void registerStates();


private:
    static const sf::Time TimePerFrame;

    sf::RenderWindow mWindow;
    TextureHolder mTextures;
    FontHolder mFonts;
    Player mPlayer;

    StateStack mStateStack;

    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};

#endif //CATRPG_APPLICATION_H
