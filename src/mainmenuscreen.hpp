#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP

#include "screen.hpp"
#include "button.hpp"
#include "label.hpp"

class MainMenuScreen : public Screen {
    private:
        sf::View *view;

        sf::Texture normalPlay;
        sf::Texture clickedPlay;
        sf::Texture hoverPlay;
        Button *playButton;

        Label *label;

    public:
        MainMenuScreen(sf::View *view);

        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void handleEvent(sf::Event &event);

        void start();
};

#endif
