//
// Created by bob on 2-5-2015.
//

#include <src/helpers/utility.h>
#include <src/entity/dataTables.h>
#include "pickup.h"

namespace
{
    const std::vector<PickupData> Table = initializePickupData();
}

Pickup::Pickup(Type type, const TextureHolder& textures)
        : Entity(1)
        , mType(type)
        , mSprite(textures.get(Table[type].texture))
{
    centerOrigin(mSprite);
}

unsigned int Pickup::getCategory() const
{
    return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const
{
    return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Pickup::apply(Aircraft& player) const
{
    Table[mType].action(player);
}

void Pickup::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

