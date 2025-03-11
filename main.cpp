#include <iostream>
#include <SFML/Graphics.hpp>
#include "configuration.h"
#include <ctime>
using namespace sf;

struct gem {
    int row{},column{},type{},match;
    float x{},y{};
    gem() {match = 0;}
}grid[9][9];

int main()
{
    std::srand(std::time(nullptr));

    RenderWindow window(VideoMode({630, 630}), "3-match Game");
    window.setFramerateLimit(60);

    const Texture t1("assets/board.png");
    const Texture t2("assets/gems.png");

    Sprite background(t1), gems(t2);
    background.setScale({5,5});

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            grid[i][j].type = std::rand() % 5;
            grid[i][j].column = j;
            grid[i][j].row = i;
            grid[i][j].x = j * CELL_SIZE * SCALE - offset;
            grid[i][j].y = i * CELL_SIZE * SCALE - offset;
        }
    }

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }
        //draw
        window.clear();

        window.draw(background);

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                gem g = grid[i][j];
                gems.setTextureRect(IntRect({g.type*13, 0}, {12,12}));
                gems.setScale({SCALE,SCALE});
                gems.setPosition({g.x,g.y});
                window.draw(gems);
            }
        }

        window.display();
    }
}
