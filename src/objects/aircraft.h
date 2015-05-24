//
// Created by bob on 29-4-2015.
//

#ifndef CATRPG_AIRCRAFT_H
#define CATRPG_AIRCRAFT_H

#include <SFML/Graphics/Sprite.hpp>
#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>
#include <src/entity/entity.h>
#include <src/command/CommandQueue.h>
#include <src/scene/textNode.h>
#include <src/animation/animation.h>
#include "projectile.h"

class Aircraft : public Entity {
public:
    enum Type {
        Eagle,
        Raptor,
        Avenger,
        TypeCount
    };


public:
    Aircraft(Type type, const TextureHolder &textures, const FontHolder &fonts);

    virtual unsigned int getCategory() const;

    virtual sf::FloatRect getBoundingRect() const;

    virtual bool isMarkedForRemoval() const;

    bool isAllied() const;

    float getMaxSpeed() const;

    void increaseFireRate();

    void increaseSpread();

    void collectMissiles(unsigned int count);

    void fire();

    void launchMissile();


private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

    virtual void updateCurrent(sf::Time dt, CommandQueue &commands);

    void updateMovementPattern(sf::Time dt);

    void checkPickupDrop(CommandQueue &commands);

    void checkProjectileLaunch(sf::Time dt, CommandQueue &commands);

    void createBullets(SceneNode &node, const TextureHolder &textures) const;

    void createProjectile(SceneNode &node, Projectile::Type type, float xOffset, float yOffset,
                          const TextureHolder &textures) const;

    void createPickup(SceneNode &node, const TextureHolder &textures) const;

    void updateTexts();


private:
    Type mType;
    sf::Sprite mSprite;
    Command mFireCommand;
    Command mMissileCommand;
    sf::Time mFireCountdown;
    bool mIsFiring;
    bool mIsLaunchingMissile;
    bool mIsMarkedForRemoval;

    int mFireRateLevel;
    int mSpreadLevel;
    int mMissileAmmo;

    Command mDropPickupCommand;
    float mTravelledDistance;
    std::size_t mDirectionIndex;
    TextNode *mHealthDisplay;
    TextNode *mMissileDisplay;

    Animation mExplosion;
    bool mShowExplosion;
    bool mSpawnedPickup;

    void updateRollAnimation();
};

#endif //CATRPG_AIRCRAFT_H

