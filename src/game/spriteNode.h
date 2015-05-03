//
// Created by bob on 30-4-2015.
//

#ifndef CATRPG_SPRITENODE_H
#define CATRPG_SPRITENODE_H

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <src/scene/sceneNode.h>

class SpriteNode : public SceneNode
{
    public:
        explicit       SpriteNode(const sf::Texture& texture);
                       SpriteNode(const sf::Texture& texture,
                                  const sf::IntRect& rect);
    private:
        virtual void   drawCurrent(sf::RenderTarget& target,
                                   sf::RenderStates states) const;
    private:
        sf::Sprite     mSprite;
};
#endif //CATRPG_SPRITENODE_H
