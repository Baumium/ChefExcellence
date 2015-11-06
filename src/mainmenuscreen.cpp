#include "mainmenuscreen.hpp"
#include "game.hpp"
#include <iostream>

MainMenuScreen::MainMenuScreen(sf::View *view) {
    this->view = view;

    normalPlay.loadFromFile("./res/ui/normalButton.png");
    clickedPlay.loadFromFile("./res/ui/clickedButton.png");
    font.loadFromFile("./res/ui/arial.ttf");

    title.setFont(font);
    title.setString("Chef Excellence");
    title.setColor(sf::Color::Blue);
    title.setPosition((Game::SCREEN_WIDTH - title.getGlobalBounds().width) / 2, title.getGlobalBounds().height * 2);

    playButton = new Button(normalPlay, clickedPlay, clickedPlay, (Game::SCREEN_WIDTH - normalPlay.getSize().x) / 2, (Game::SCREEN_HEIGHT - title.getPosition().y + title.getGlobalBounds().height) / 2, "Start Game", font, 24, sf::Color::White);


}

void MainMenuScreen::update() {

}

void MainMenuScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(title, states);
    target.draw(*playButton, states);
}

void MainMenuScreen::handleEvent(sf::Event &event) {
    playButton->update(event);
}

void MainMenuScreen::start() {
    Screen::start();
    view->reset(sf::FloatRect(0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT));
}
