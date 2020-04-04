#pragma once

#include "tetro.h"

void board_create(int rows, int cols);
void board_free();
char *board_get();

void board_addToBoard(tetro *t, int screenCols);
int board_collides(tetro *t);
int board_len();