#include "mainmenuscreen.hpp"
#include "game.hpp"
#include <iostream>

MainMenuScreen::MainMenuScreen(sf::View *view) {
    this->view = view;

    normalPlay.loadFromFile("./assets/ui/normalButton.png");
    clickedPlay.loadFromFile("./assets/ui/clickedButton.png");
    playButton = new Button(normalPlay, clickedPlay, clickedPlay, 50, 50);
}

void MainMenuScreen::update() {

}

void MainMenuScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*playButton, states);
}

void MainMenuScreen::handleEvent(sf::Event &event) {
    playButton->update(event);
}

void MainMenuScreen::start() {
    Screen::start();
    view->reset(sf::FloatRect(0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT));
}
