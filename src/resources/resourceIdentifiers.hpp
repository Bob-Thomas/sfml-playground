#ifndef CATRPG_RESOURCEIDENTIFIERS_HPP
#define CATRPG_RESOURCEIDENTIFIERS_HPP


// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}
namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Avenger,
        Missile,
        Bullet,
        HealthRefill,
        MissileRefill,
        FireRate,
        FireSpread,
        Desert,

        TitleScreen,
        ButtonNormal,
        ButtonSelected,
        ButtonPressed,
    };
}

namespace Fonts
{
    enum ID
    {
        Default,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif // CATRPG_RESOURCEIDENTIFIERS_HPP