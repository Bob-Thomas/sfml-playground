//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_PROJECTILE_H
#define CATRPG_PROJECTILE_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <src/command/CommandQueue.h>
#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>
#include <src/entity/entity.h>

class Projectile : public Entity
{
public:
    enum Type
    {
        AlliedBullet,
        EnemyBullet,
        Missile,
        TypeCount
    };


public:
    Projectile(Type type, const TextureHolder& textures);

    void					guideTowards(sf::Vector2f position);
    bool					isGuided() const;

    virtual unsigned int	getCategory() const;
    virtual sf::FloatRect	getBoundingRect() const;
    float					getMaxSpeed() const;
    int						getDamage() const;


private:
    virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
    virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
    Type					mType;
    sf::Sprite				mSprite;
    sf::Vector2f			mTargetDirection;
};
#endif //CATRPG_PROJECTILE_H
