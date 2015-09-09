#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "screen.hpp"
#include "player.hpp"
#include "levelhandler.hpp"

class GameScreen : public Screen {
    private:
        //For use in animations
        sf::Clock frameClock;

        //Chef stuffs
        sf::Texture chefStandingRight;
        sf::Texture chefStandingLeft;
        sf::Texture chefWalkingRight;
        sf::Texture chefWalkingLeft;
        sf::Texture chefClimbing;
        sf::Texture breadstick;
        Player *player;

        //Level stuffs
        sf::Texture background;
        sf::Texture platform;
        Level *level;
        std::vector<Level> levels;
        LevelHandler *levelHandler;

        //Camera that follows the player (typlically)
        sf::View *view;

    public:
        GameScreen(sf::View *view);

        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void handleEvent(sf::Event event);
};


#endif
