//
// Created by bob on 15-5-2015.
//

#ifndef CATRPG_PARTICLE_H
#define CATRPG_PARTICLE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>

struct Particle {
    enum Type {
        Propellant,
        Smoke,
        ParticleCount
    };

    sf::Vector2f position;
    sf::Color color;
    sf::Time lifetime;
};
#endif //CATRPG_PARTICLE_H
