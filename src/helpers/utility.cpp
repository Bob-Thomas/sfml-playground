//
// Created by bob on 1-5-2015.
//

#include "utility.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include <assert.h>

namespace
{
    std::default_random_engine createRandomEngine()
    {
        auto seed = static_cast<unsigned long>(std::time(nullptr));
        return std::default_random_engine(seed);
    }

    auto RandomEngine = createRandomEngine();
}

std::string toString(sf::Keyboard::Key key)
{
#define CATRPG_KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;

    switch (key)
    {
        CATRPG_KEYTOSTRING_CASE(Unknown)
        CATRPG_KEYTOSTRING_CASE(A)
        CATRPG_KEYTOSTRING_CASE(B)
        CATRPG_KEYTOSTRING_CASE(C)
        CATRPG_KEYTOSTRING_CASE(D)
        CATRPG_KEYTOSTRING_CASE(E)
        CATRPG_KEYTOSTRING_CASE(F)
        CATRPG_KEYTOSTRING_CASE(G)
        CATRPG_KEYTOSTRING_CASE(H)
        CATRPG_KEYTOSTRING_CASE(I)
        CATRPG_KEYTOSTRING_CASE(J)
        CATRPG_KEYTOSTRING_CASE(K)
        CATRPG_KEYTOSTRING_CASE(L)
        CATRPG_KEYTOSTRING_CASE(M)
        CATRPG_KEYTOSTRING_CASE(N)
        CATRPG_KEYTOSTRING_CASE(O)
        CATRPG_KEYTOSTRING_CASE(P)
        CATRPG_KEYTOSTRING_CASE(Q)
        CATRPG_KEYTOSTRING_CASE(R)
        CATRPG_KEYTOSTRING_CASE(S)
        CATRPG_KEYTOSTRING_CASE(T)
        CATRPG_KEYTOSTRING_CASE(U)
        CATRPG_KEYTOSTRING_CASE(V)
        CATRPG_KEYTOSTRING_CASE(W)
        CATRPG_KEYTOSTRING_CASE(X)
        CATRPG_KEYTOSTRING_CASE(Y)
        CATRPG_KEYTOSTRING_CASE(Z)
        CATRPG_KEYTOSTRING_CASE(Num0)
        CATRPG_KEYTOSTRING_CASE(Num1)
        CATRPG_KEYTOSTRING_CASE(Num2)
        CATRPG_KEYTOSTRING_CASE(Num3)
        CATRPG_KEYTOSTRING_CASE(Num4)
        CATRPG_KEYTOSTRING_CASE(Num5)
        CATRPG_KEYTOSTRING_CASE(Num6)
        CATRPG_KEYTOSTRING_CASE(Num7)
        CATRPG_KEYTOSTRING_CASE(Num8)
        CATRPG_KEYTOSTRING_CASE(Num9)
        CATRPG_KEYTOSTRING_CASE(Escape)
        CATRPG_KEYTOSTRING_CASE(LControl)
        CATRPG_KEYTOSTRING_CASE(LShift)
        CATRPG_KEYTOSTRING_CASE(LAlt)
        CATRPG_KEYTOSTRING_CASE(LSystem)
        CATRPG_KEYTOSTRING_CASE(RControl)
        CATRPG_KEYTOSTRING_CASE(RShift)
        CATRPG_KEYTOSTRING_CASE(RAlt)
        CATRPG_KEYTOSTRING_CASE(RSystem)
        CATRPG_KEYTOSTRING_CASE(Menu)
        CATRPG_KEYTOSTRING_CASE(LBracket)
        CATRPG_KEYTOSTRING_CASE(RBracket)
        CATRPG_KEYTOSTRING_CASE(SemiColon)
        CATRPG_KEYTOSTRING_CASE(Comma)
        CATRPG_KEYTOSTRING_CASE(Period)
        CATRPG_KEYTOSTRING_CASE(Quote)
        CATRPG_KEYTOSTRING_CASE(Slash)
        CATRPG_KEYTOSTRING_CASE(BackSlash)
        CATRPG_KEYTOSTRING_CASE(Tilde)
        CATRPG_KEYTOSTRING_CASE(Equal)
        CATRPG_KEYTOSTRING_CASE(Dash)
        CATRPG_KEYTOSTRING_CASE(Space)
        CATRPG_KEYTOSTRING_CASE(Return)
        CATRPG_KEYTOSTRING_CASE(BackSpace)
        CATRPG_KEYTOSTRING_CASE(Tab)
        CATRPG_KEYTOSTRING_CASE(PageUp)
        CATRPG_KEYTOSTRING_CASE(PageDown)
        CATRPG_KEYTOSTRING_CASE(End)
        CATRPG_KEYTOSTRING_CASE(Home)
        CATRPG_KEYTOSTRING_CASE(Insert)
        CATRPG_KEYTOSTRING_CASE(Delete)
        CATRPG_KEYTOSTRING_CASE(Add)
        CATRPG_KEYTOSTRING_CASE(Subtract)
        CATRPG_KEYTOSTRING_CASE(Multiply)
        CATRPG_KEYTOSTRING_CASE(Divide)
        CATRPG_KEYTOSTRING_CASE(Left)
        CATRPG_KEYTOSTRING_CASE(Right)
        CATRPG_KEYTOSTRING_CASE(Up)
        CATRPG_KEYTOSTRING_CASE(Down)
        CATRPG_KEYTOSTRING_CASE(Numpad0)
        CATRPG_KEYTOSTRING_CASE(Numpad1)
        CATRPG_KEYTOSTRING_CASE(Numpad2)
        CATRPG_KEYTOSTRING_CASE(Numpad3)
        CATRPG_KEYTOSTRING_CASE(Numpad4)
        CATRPG_KEYTOSTRING_CASE(Numpad5)
        CATRPG_KEYTOSTRING_CASE(Numpad6)
        CATRPG_KEYTOSTRING_CASE(Numpad7)
        CATRPG_KEYTOSTRING_CASE(Numpad8)
        CATRPG_KEYTOSTRING_CASE(Numpad9)
        CATRPG_KEYTOSTRING_CASE(F1)
        CATRPG_KEYTOSTRING_CASE(F2)
        CATRPG_KEYTOSTRING_CASE(F3)
        CATRPG_KEYTOSTRING_CASE(F4)
        CATRPG_KEYTOSTRING_CASE(F5)
        CATRPG_KEYTOSTRING_CASE(F6)
        CATRPG_KEYTOSTRING_CASE(F7)
        CATRPG_KEYTOSTRING_CASE(F8)
        CATRPG_KEYTOSTRING_CASE(F9)
        CATRPG_KEYTOSTRING_CASE(F10)
        CATRPG_KEYTOSTRING_CASE(F11)
        CATRPG_KEYTOSTRING_CASE(F12)
        CATRPG_KEYTOSTRING_CASE(F13)
        CATRPG_KEYTOSTRING_CASE(F14)
        CATRPG_KEYTOSTRING_CASE(F15)
        CATRPG_KEYTOSTRING_CASE(Pause)
    }

    return "";
}

void centerOrigin(sf::Sprite& sprite)
{
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

float toDegree(float radian)
{
    return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree)
{
    return 3.141592653589793238462643383f / 180.f * degree;
}

int randomInt(int exclusiveMax)
{
    std::uniform_int_distribution<> distr(0, exclusiveMax - 1);
    return distr(RandomEngine);
}

float length(sf::Vector2f vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f unitVector(sf::Vector2f vector)
{
    assert(vector != sf::Vector2f(0.f, 0.f));
    return vector / length(vector);
}