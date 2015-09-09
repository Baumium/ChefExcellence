#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP

#include "screen.hpp"
#include "button.hpp"

class MainMenuScreen : public Screen {
    private:
        sf::Texture normalPlay;
        sf::Texture clickedPlay;
        sf::Texture hoverPlay;
        Button *playButton;

    public:
        MainMenuScreen();

        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void handleEvent(sf::Event event);
};

#endif
