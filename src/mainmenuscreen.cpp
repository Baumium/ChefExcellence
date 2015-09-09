#include "mainmenuscreen.hpp"

MainMenuScreen::MainMenuScreen() {
    normalPlay.loadFromFile("./assets/ui/normalButton.png");
    clickedPlay.loadFromFile("./assets/ui/clickedButton.png");
    playButton = new Button(normalPlay, clickedPlay, normalPlay, 50, 50);
}

void MainMenuScreen::update() {

}

void MainMenuScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*playButton, states);
}

void MainMenuScreen::handleEvent(sf::Event event) {
    //Check if mouse is released on top of the button
    if(event.type == sf::Event::MouseButtonReleased) {
        float x = sf::Mouse::getPosition().x;
        float y = sf::Mouse::getPosition().y;

        if(x > playButton->getX()
                && x < playButton->getX() + playButton->getWidth()
                && y > playButton->getY()
                && y < playButton->getY() + playButton->getHeight()) {
            playButton->changeState(Button::CLICKED);
        }
    }
}
