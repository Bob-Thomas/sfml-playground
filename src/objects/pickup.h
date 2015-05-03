//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_PICKUP_H
#define CATRPG_PICKUP_H

#include <SFML/Graphics/Sprite.hpp>
#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>
#include <src/entity/entity.h>

class Aircraft;

class Pickup : public Entity
{
public:
    enum Type
    {
        HealthRefill,
        MissileRefill,
        FireSpread,
        FireRate,
        TypeCount
    };


public:
    Pickup(Type type, const TextureHolder& textures);

    virtual unsigned int	getCategory() const;
    virtual sf::FloatRect	getBoundingRect() const;

    void 					apply(Aircraft& player) const;


protected:
    virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
    Type 					mType;
    sf::Sprite				mSprite;
};

#endif //CATRPG_PICKUP_H
