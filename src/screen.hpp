#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>

class Screen : public sf::Drawable {
    public:
        Screen();
        void show();
        void hide();
        void start();
        void pause();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update();
        virtual void handleEvent(sf::Event event);

    private:
        bool isVisible;
        bool isPaused;
};

#endif
