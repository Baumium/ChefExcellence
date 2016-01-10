#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

class Button : public sf::Drawable {
    private:
        sf::Texture normal;
        sf::Texture clicked;
        sf::Texture hovered;

        sf::Sprite sprite;

        sf::Text label;

    public:
        Button(sf::Texture &normal, sf::Texture &clicked, sf::Texture &hovered, float x, float y, std::string str, sf::Font &font, float charSize, sf::Color color);

        enum ButtonState {
            NORMAL,
            CLICKED,
            HOVERED
        };

        void update(sf::Event &event);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void changeState(ButtonState state);
        bool checkOverlap(float x, float y);
        float getX();
        float getY();
        float getWidth();
        float getHeight();
};

#endif
