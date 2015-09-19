#include "label.hpp"

Label::Label(std::string str, float x, float y, sf::Font &font, float charSize = 24, sf::Color color = sf::Color::White) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(charSize);
    text.setColor(color);
    text.setPosition(x, y);
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}
