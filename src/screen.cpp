#include "screen.hpp"

Screen::Screen() {
    isVisible = false;
    isPaused = true;
}

void Screen::show() {
    isVisible = true;
}

void Screen::hide() {
    isVisible = false;
}

void Screen::pause() {
    isPaused = true;
}

void Screen::start() {
    isPaused = false;
}

void Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}

void Screen::update() {

}

void Screen::handleEvent(sf::Event &event) {

}
