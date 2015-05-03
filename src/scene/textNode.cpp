//
// Created by bob on 3-5-2015.
//

#include "textNode.h"
#include <src/resources/resourceHolder.hpp>
#include <src/helpers/utility.h>

TextNode::TextNode(const FontHolder &fonts, const std::string &text) {
    mText.setFont(fonts.get(Fonts::Default));
    mText.setCharacterSize(20);
    setString(text);
}

void TextNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
}

void TextNode::setString(const std::string &text) {
    mText.setString(text);
    centerOrigin(mText);
}