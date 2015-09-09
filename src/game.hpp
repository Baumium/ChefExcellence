#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "gamescreen.hpp"
#include "mainmenuscreen.hpp"
#include "level.hpp"
#include "levelhandler.hpp"

class Game {
    private:
        bool isPlaying;

        sf::RenderWindow window;
        sf::View view;

        sf::Clock frameClock;

        //Screens
        Screen *currentScreen;
        GameScreen *gameScreen;
        MainMenuScreen *mainMenuScreen;

        void update();
        void render();
        void setScreen(Screen *screen);

    public:
        Game();
        void execute();

        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;
};

#endif
