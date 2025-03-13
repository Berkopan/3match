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

    grid[g1.row][g1.column] = g1;
    grid[g2.row][g2.column] = g2;
}

int main()
{
    std::srand(std::time(nullptr));

    RenderWindow window(VideoMode({630, 630}), "3-match Game", sf::Style::Close );
    window.setFramerateLimit(60);
    window.requestFocus();

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

    int in_i,in_j,final_i,final_j = -1;
    bool isMoving, isSwap = false;
    while (window.isOpen()) {
        while (const std::optional<Event> event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();

            if (auto mouseEvent = event->getIf<Event::MouseButtonPressed>()) {
                in_i = mouseEvent->position.y / (CELL_SIZE * SCALE);
                in_j = mouseEvent->position.x / (CELL_SIZE * SCALE);
                std::cout << grid[in_i][in_j].match;
            }
            if (auto mouseEvent = event->getIf<Event::MouseButtonReleased>()) {
                final_i = mouseEvent->position.y / (CELL_SIZE * SCALE);
                final_j = mouseEvent->position.x / (CELL_SIZE * SCALE);
                if (0 <= in_i && in_i < BOARD_SIZE && 0 <= in_j && in_j < BOARD_SIZE && 0 <= final_i && final_i < BOARD_SIZE && 0 <= final_j && final_j < BOARD_SIZE) {
                    if (in_i == final_i && in_j != final_j) {
                        if (-1 <= final_j - in_j && final_j - in_j <= 1) {
                            isSwap = true;
                            swap(grid[in_i][in_j], grid[final_i][final_j]);
                        }
                    } else if (in_j == final_j && in_i != final_i) {
                        if (-1 <= final_i - in_i && final_i - in_i <= 1) {
                            isSwap = true;
                            swap(grid[in_i][in_j], grid[final_i][final_j]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (j != 0 && grid[i][j - 1].type == grid[i][j].type)
                    if (j != BOARD_SIZE - 1 && grid[i][j + 1].type == grid[i][j].type) {
                        for (int n = -1; n <= 1; ++n) {
                            grid[i][j + n].match = 1;
                        }
                    }
                if (i != 0 && grid[i - 1][j].type == grid[i][j].type)
                    if (i != BOARD_SIZE - 1 && grid[i + 1][j].type == grid[i][j].type) {
                        for (int n = -1; n <= 1; ++n) {
                            grid[i + n][j].match = 1;
                        }
                    }
            }
        }

        isMoving = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                gem &g = grid[i][j];
                int dx,dy;
                for (int n = 0; n < SWAP_SPEED; ++n) {
                    dx = g.x - (j * CELL_SIZE * SCALE - offset);
                    dy = g.y - (i * CELL_SIZE * SCALE - offset);
                    if (dx) g.x -= dx/abs(dx);
                    if (dy) g.y -= dy/abs(dy);
                    if (dx || dy) {
                        isMoving = true;
                    }
                }
            }
        }


        if (!isMoving) {
            for (int i = 0; i < BOARD_SIZE; ++i) {
                for (int j = 0; j < BOARD_SIZE; ++j) {
                    if (grid[i][j].match == 1) {
                        for (int n = i; n > 0; --n) {
                            swap(grid[n][j], grid[n-1][j]);
                        }
                        grid[0][j].type = std::rand() % 5;
                        grid[0][j].y = -100;
                        grid[0][j].match = 0;
                    }
                }
            }
        }

        if (isSwap && !isMoving) {
            if (grid[in_i][in_j].match == 0 && grid[final_i][final_j].match == 0) {
                swap(grid[in_i][in_j], grid[final_i][final_j]);
                isSwap = false;
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
