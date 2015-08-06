#include "game.hpp"
#include "direction.hpp"
#include "screen.hpp"
#include "pugixml.hpp"
#include <iostream>

const int Game::SCREEN_WIDTH = 1366;
const int Game::SCREEN_HEIGHT = 768;

Game::Game() {
    //Set up rendering window
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chef Excellence"/*, sf::Style::Fullscreen*/);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    window.setView(view);

    isPlaying = true;

    //Screens
    currentScreen = NULL;
    gameScreen = new GameScreen(&view);

    //Start game with game screen (temporary until menu screen created)
    setScreen(gameScreen);
}

void Game::update() {
    sf::Event event;
    while(window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                    case sf::Keyboard::LControl:
                        isPlaying = !isPlaying;
                    default:
                        break;

                }
                break;
            default:
                break;
        }
    }

    if(isPlaying) {
        currentScreen->update();
    }
}

void Game::render() {
    window.clear(sf::Color::Red);

    window.draw(*currentScreen);

    window.setView(view);
    window.display();
}

void Game::execute() {
    while(window.isOpen()) {
        update();
        render();
    }
}

void Game::setScreen(Screen *screen) {
    currentScreen = screen;
}
