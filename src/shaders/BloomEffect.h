//
// Created by bob on 24-5-2015.
//


#ifndef CATRPG_BLOOMEFFECT_H
#define CATRPG_BLOOMEFFECT_H
#include "PostEffect.h"

#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>

class BloomEffect : public PostEffect
{
public:
    BloomEffect();

    virtual void		apply(const sf::RenderTexture& input, sf::RenderTarget& output);


private:
    typedef std::array<sf::RenderTexture, 2> RenderTextureArray;


private:
    void				prepareTextures(sf::Vector2u size);

    void				filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
    void				blurMultipass(RenderTextureArray& renderTextures);
    void				blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
    void				downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
    void				add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& target);


private:
    ShaderHolder		mShaders;

    sf::RenderTexture	mBrightnessTexture;
    RenderTextureArray	mFirstPassTextures;
    RenderTextureArray	mSecondPassTextures;
};
#endif //CATRPG_BLOOMEFFECT_H
