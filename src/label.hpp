#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>

class Label : sf::Drawable {
    private:
        sf::Text text;

    public:
        Label(std::string text, float x, float y, sf::Font &font, float charSize, sf::Color color);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
