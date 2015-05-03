//
// Created by bob on 2-5-2015.
//

#ifndef CATRPG_LABEL_H
#define CATRPG_LABEL_H
#include <src/gui/component.h>
#include <src/resources/resourceIdentifiers.hpp>
#include <src/resources/resourceHolder.hpp>

#include <SFML/Graphics/Text.hpp>


namespace GUI
{

    class Label : public Component
    {
    public:
        typedef std::shared_ptr<Label> Ptr;


    public:
        Label(const std::string& text, const FontHolder& fonts);

        virtual bool		isSelectable() const;
        void				setText(const std::string& text);

        virtual void		handleEvent(const sf::Event& event);


    private:
        void				draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        sf::Text			mText;
    };

}
#endif //CATRPG_LABEL_H
