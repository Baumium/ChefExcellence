#include "button.hpp"
#include "game.hpp"
#include <iostream>

Button::Button(sf::Texture &normal, sf::Texture &clicked, sf::Texture &hovered, float x, float y, std::string str, sf::Font &font, float charSize, sf::Color color) {
    this->normal = normal;
    this->clicked = clicked;
    this->hovered = hovered;
    sprite = sf::Sprite(normal);
    sprite.setPosition(x, y);

    label.setString(str);
    label.setFont(font);
    label.setCharacterSize(charSize);
    label.setColor(color);
    label.setPosition(x + (sprite.getGlobalBounds().width - label.getGlobalBounds().width) / 2,
            y + (sprite.getGlobalBounds().height - label.getGlobalBounds().height) / 4);
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
    target.draw(label, states);
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

bool Button::checkOverlap(float x, float y) {
    if(x > getX()
            && x < getX() + getWidth()
            && y > getY()
            && y < getY() + getHeight()) {
        return true;
    } else {
        return false;
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

void Button::update(sf::Event &event) {
    //Check is mouse is hovering over button
    if(event.type == sf::Event::MouseMoved) {
        if(checkOverlap(event.mouseMove.x, event.mouseMove.y)) {
            changeState(HOVERED);
        } else {
            changeState(NORMAL);
        }
    } else if(event.type == sf::Event::MouseButtonPressed) {
        //Likewise, check if mouse is pressed on top of the button
        if(checkOverlap(event.mouseButton.x, event.mouseButton.y)) {
            changeState(CLICKED);
        }
    } else if(event.type == sf::Event::MouseButtonReleased) {
        if(checkOverlap(event.mouseButton.x, event.mouseButton.y)) {
            //TODO: Perform button action when mouse is released on button
            Game::setScreen(Game::gameScreen);
        }
    }
}
