//
// Created by bob on 2-5-2015.
//

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <memory>
#include <SFML/Window/Event.hpp>

#ifndef CATRPG_COMPONENT_H
#define CATRPG_COMPONENT_H

namespace GUI
{
    class Component : public sf::Drawable
                    , public sf::Transformable
                    , public sf::NonCopyable
    {
    public:
        typedef std::shared_ptr<Component> Ptr;

    public:
        Component();
        virtual ~Component();
        virtual bool isSelectable() const = 0;
        virtual void select();
        virtual void deselect();
        virtual void activate();
        virtual void deactivate();
        virtual void handleEvent(const sf::Event& event) = 0;
        virtual bool isActive() const;
        bool isSelected() const;
    private:
        bool mIsSelected;
        bool mIsActive;
    };
}

#endif //CATRPG_COMPONENT_H
