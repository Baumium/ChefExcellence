#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "screen.hpp"
#include "levelhandler.hpp"
#include "level.hpp"

class GameScreen : public Screen {
    private:
        //For use in animations
        sf::Clock frameClock;

        //Chef stuffs
        sf::Texture chefSheet;
        sf::Texture breadstick;

        //Level stuffs
        sf::Texture background;
        sf::Texture platform;
        Level level;
        std::vector<Level> levels;
        LevelHandler *levelHandler;

        //Camera that follows the player (typlically)
        sf::View *view;

    public:
        GameScreen(sf::View *view);

        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void handleEvent(sf::Event &event);

        void start();
};


#endif
