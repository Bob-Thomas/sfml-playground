//
// Created by bob on 24-5-2015.
//

#ifndef CATRPG_POSTEFFECT_H
#define CATRPG_POSTEFFECT_H

#include <SFML/Graphics.hpp>

class PostEffect
{
public:
    virtual ~PostEffect();
    virtual void apply(const sf::RenderTexture& input, sf::RenderTarget&  output) = 0;
    static bool isSupported();

protected:
    static void applyShader(const sf::Shader& shader, sf::RenderTarget& output);


};
#endif //CATRPG_POSTEFFECT_H
