#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "configuration.h"
#include <ctime>
using namespace sf;

struct gem {
    int row{},column{},type{},match;
    float x{},y{};
    gem() {match = 0;}
}grid[9][9];

void swap(gem g1, gem g2) {
    std::swap(g1.column,g2.column);
    std::swap(g1.row, g2.row);
    std::swap(g1.x, g2.x);
    std::swap(g1.y, g2.y);

    grid[g1.row][g1.column] = g1;
    grid[g2.row][g2.column] = g2;
}

int main()
{
    std::srand(std::time(nullptr));

    RenderWindow window(VideoMode({630, 630}), "3-match Game", sf::Style::Titlebar | sf::Style::Close);
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

    int in_i = -1;
    int in_j = -1;

    while (window.isOpen()) {
        while (const std::optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();

            if (auto mouseEvent = event->getIf<Event::MouseButtonPressed>()) {
                in_i = mouseEvent->position.y / (CELL_SIZE * SCALE);
                in_j = mouseEvent->position.x / (CELL_SIZE * SCALE);
            }
            if (auto mouseEvent = event->getIf<Event::MouseButtonReleased>()) {
                int final_i = mouseEvent->position.y / (CELL_SIZE * SCALE);
                int final_j = mouseEvent->position.x / (CELL_SIZE * SCALE);
                if (in_i == final_i && in_j != final_j) {
                    if (-1 <= final_j - in_j && final_j - in_j <= 1) {
                        swap(grid[in_i][in_j], grid[final_i][final_j]);
                    }
                } else if (in_j == final_j && in_i != final_i) {
                    if (-1 <= final_i - in_i && final_i - in_i <= 1) {
                        swap(grid[in_i][in_j], grid[final_i][final_j]);
                    }
                }
            }
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
