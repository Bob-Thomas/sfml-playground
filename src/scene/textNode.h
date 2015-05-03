//
// Created by bob on 3-5-2015.
//

#ifndef CATRPG_TEXTNODE_H
#define CATRPG_TEXTNODE_H

#include <src/resources/resourceIdentifiers.hpp>
#include "sceneNode.h"

class TextNode : public SceneNode
{
public:
    explicit TextNode(const FontHolder& fonts,
                      const std::string& text);
    void setString(const std::string& text);
private:
    virtual void drawCurrent(sf::RenderTarget& target,
                             sf::RenderStates states) const;

private:
    sf::Text mText;
};


#endif //CATRPG_TEXTNODE_H
