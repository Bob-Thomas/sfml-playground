//
// Created by bob on 29-4-2015.
//

#ifndef CATRPG_ENTITY_H
#define CATRPG_ENTITY_H

#include <SFML/System/Vector2.hpp>
#include <src/scene/sceneNode.h>

class Entity : public SceneNode {
public:
    explicit Entity(int hitpoints);

    void repair(int points);

    void damage(int points);

    void destroy();

    void setVelocity(sf::Vector2f velocity);

    void setVelocity(float vx, float vy);

    void accelerate(sf::Vector2f velocity);

    void accelerate(float vy, float vx);

    int getHitpoints() const;

    bool isDestroyed() const;

    sf::Vector2f getVelocity() const;

protected:
    virtual void		updateCurrent(sf::Time dt, CommandQueue& commands);

private:
    int mHitpoints;
    sf::Vector2f mVelocity;
};

#endif //CATRPG_ENTITY_H
