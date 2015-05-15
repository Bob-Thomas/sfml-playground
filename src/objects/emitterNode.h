//
// Created by bob on 15-5-2015.
//


#ifndef CATRPG_EMITTERNODE_H
#define CATRPG_EMITTERNODE_H

#include <src/scene/sceneNode.h>
#include "particle.h"

class ParticleNode;

class EmitterNode : public SceneNode
{
public:
    explicit				EmitterNode(Particle::Type type);


private:
    virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);

    void					emitParticles(sf::Time dt);


private:
    sf::Time				mAccumulatedTime;
    Particle::Type			mType;
    ParticleNode*			mParticleSystem;
};


#endif //CATRPG_EMITTERNODE_H
