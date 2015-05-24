#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "level.hpp"

class Game {
    private:
        bool isPlaying;

        sf::RenderWindow window;
        sf::View view;

        sf::Clock frameClock;

        sf::Texture chefStandingRight;
        sf::Texture chefStandingLeft;
        sf::Texture chefWalkingRight;
        sf::Texture chefWalkingLeft;
        sf::Texture chefClimbing;
        sf::Texture breadstick;
        Player *player;

        sf::Texture background;
        Level *level;

    public:
        Game();
        void execute();
        void update();
        void render();

        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;
};

#endif
