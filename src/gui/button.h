//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_BUTTON_H
#define CATRPG_BUTTON_H

#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "component.h"
#include <functional>
namespace GUI
{

    class Button : public Component
    {
    public:
        typedef std::shared_ptr<Button>		Ptr;
        typedef std::function<void()>		Callback;


    public:
        Button(const FontHolder& fonts, const TextureHolder& textures);

        void					setCallback(Callback callback);
        void					setText(const std::string& text);
        void					setToggle(bool flag);

        virtual bool			isSelectable() const;
        virtual void			select();
        virtual void			deselect();

        virtual void			activate();
        virtual void			deactivate();

        virtual void			handleEvent(const sf::Event& event);


    private:
        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        Callback				mCallback;
        const sf::Texture&		mButtonTexture;
        sf::IntRect       mButtonDefaultRect;
        sf::IntRect       mButtonSelectedRect;
        sf::IntRect       mButtonPressedRect;
        sf::Sprite				mSprite;
        sf::Text				mText;
        bool					mIsToggle;
    };

}
#endif //CATRPG_BUTTON_H
