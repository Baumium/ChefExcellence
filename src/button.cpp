#include "button.hpp"

Button::Button(sf::Texture &normal, sf::Texture &clicked, sf::Texture &hovered, float x, float y) {
    this->normal = normal;
    this->clicked = clicked;
    this->hovered = hovered;
    sprite = sf::Sprite(normal);
    sprite.setPosition(x, y);
}

void Button::update() {

}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Button::changeState(ButtonState state) {
    switch(state) {
        case NORMAL:
            sprite.setTexture(normal);
            break;
        case CLICKED:
            sprite.setTexture(clicked);
            break;
        case HOVERED:
            sprite.setTexture(hovered);
            break;
    }
}

float Button::getX() {
    return sprite.getPosition().x;
}

float Button::getY() {
    return sprite.getPosition().y;
}

float Button::getWidth() {
    return sprite.getGlobalBounds().width;
}

float Button::getHeight() {
    return sprite.getGlobalBounds().height;
}
