//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_DATATABLES_H
#define CATRPG_DATATABLES_H

#include <vector>
#include <functional>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <src/resources/resourceIdentifiers.hpp>

class Aircraft;

struct Direction
{
    Direction(float angle, float distance)
            : angle(angle)
            , distance(distance)
    {
    }

    float angle;
    float distance;
};

struct AircraftData
{
    int								hitpoints;
    float							speed;
    Textures::ID					texture;
    sf::IntRect                     textureRect;
    sf::Time						fireInterval;
    std::vector<Direction>			directions;
    bool                            hasRollAnimation;
};

struct ProjectileData
{
    int								damage;
    float							speed;
    Textures::ID					texture;
    sf::IntRect                     textureRect;
};

struct PickupData
{
    std::function<void(Aircraft&)>	action;
    Textures::ID					texture;
    sf::IntRect                     textureRect;
};

struct ParticleData
{
    sf::Color color;
    sf::Time lifetime;
};

std::vector<AircraftData>	initializeAircraftData();
std::vector<ProjectileData>	initializeProjectileData();
std::vector<PickupData>		initializePickupData();
std::vector<ParticleData>	initializeParticleData();

#endif //CATRPG_DATATABLES_H
