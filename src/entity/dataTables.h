//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_DATATABLES_H
#define CATRPG_DATATABLES_H

#include <vector>
#include <functional>
#include <SFML/System/Time.hpp>
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
    sf::Time						fireInterval;
    std::vector<Direction>			directions;
};

struct ProjectileData
{
    int								damage;
    float							speed;
    Textures::ID					texture;
};

struct PickupData
{
    std::function<void(Aircraft&)>	action;
    Textures::ID					texture;
};


std::vector<AircraftData>	initializeAircraftData();
std::vector<ProjectileData>	initializeProjectileData();
std::vector<PickupData>		initializePickupData();

#endif //CATRPG_DATATABLES_H
