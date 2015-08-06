#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "screen.hpp"
#include "player.hpp"
#include "levelhandler.hpp"

class GameScreen : public Screen {
    private:
        bool isPlaying;

        sf::RenderWindow window;
        sf::View *view;

        sf::Clock frameClock;

        sf::Texture chefStandingRight;
        sf::Texture chefStandingLeft;
        sf::Texture chefWalkingRight;
        sf::Texture chefWalkingLeft;
        sf::Texture chefClimbing;
        sf::Texture breadstick;
        Player *player;

        sf::Texture background;
        sf::Texture platform;
        Level *level;
        std::vector<Level> levels;
        LevelHandler *levelHandler;

    public:
        GameScreen(sf::View *view);

        void update();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
