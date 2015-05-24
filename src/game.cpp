#include "game.hpp"
#include "direction.hpp"

const int Game::SCREEN_WIDTH = 640;
const int Game::SCREEN_HEIGHT = 480;

Game::Game() {
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Chef Excellence");
    window.setKeyRepeatEnabled(false);
    view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
    window.setView(view);

    isPlaying = true;

    chefStandingRight.loadFromFile("assets/chef/ChefStandingRight.png");
    chefStandingLeft.loadFromFile("assets/chef/ChefStandingLeft.png");
    chefWalkingRight.loadFromFile("assets/chef/ChefWalkingRight.png");
    chefWalkingLeft.loadFromFile("assets/chef/ChefWalkingLeft.png");
    chefClimbing.loadFromFile("assets/chef/ChefClimbing.png");
    breadstick.loadFromFile("assets/chef/Breadstick1.png");
    player = new Player(chefWalkingRight, breadstick);

    background.loadFromFile("assets/map/level1/Background.png");
    level = new Level(background);
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
            default:
                break;
        }
    }

    if(isPlaying) {
        sf::Time frameTime = frameClock.restart();

        //Player vertical movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->move(LEFT);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->move(RIGHT);
        } else {
            player->move(NONE);
        }

        //Player vertical movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player->jump();
        }

        //Breadstick throwing
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player->throwBreadstick();
        }

        player->update(frameTime, sf::Vector2f(view.getCenter().x + SCREEN_WIDTH / 2, view.getCenter().y + SCREEN_HEIGHT / 2));

        view.move((player->getPosition().x - view.getCenter().x) / 10.0,
                (player->getPosition().y + player->getLocalBounds().height - SCREEN_HEIGHT / 2 - view.getCenter().y + 50) / 20.0);
        window.setView(view);
    }
}

void Game::render() {
    window.clear(sf::Color::Red);

    window.draw(*level);
    window.draw(*player);

    window.display();
}

void Game::execute() {
    while(window.isOpen()) {
        update();
        render();
    }
}
