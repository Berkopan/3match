#ifndef CONFIGURATION_H
#define CONFIGURATION_H

const int CELL_SIZE = 14;
const int BOARD_SIZE = 9;
const float SCALE = 5.0f;
const int GEM_SIZE = 12;
const int SCALED_GEM_SIZE = GEM_SIZE * SCALE;
const float offset = (SCALED_GEM_SIZE - CELL_SIZE * SCALE) / 2.0f;
const float SWAP_SPEED = 4;

#endif