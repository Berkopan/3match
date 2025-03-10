#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode({516, 516}), "3-match Game");

    const Texture texture("assets/board_9x9_dark_grey.png");
    std::cout << texture.getSize().x;
    Sprite sprite(texture);
    sprite.setScale({3,3});


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }
}
