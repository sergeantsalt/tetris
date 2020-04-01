#include "tetro.h"
#include <stdlib.h>
#include <string.h>

void tetro_rotate(tetro *t, int screenWidth) {
  if (t->o == RIGHT) {
    t->o = DOWN;
  } else {
    t->o++;
  }

  switch(t->o) {
    case DOWN:
      t->seq[0] = -screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = screenWidth + t->pos;
      t->seq[3] = 2 * screenWidth + t->pos;
      break;
    case LEFT:
      t->seq[0] = 1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -1 + t->pos;
      t->seq[3] = -2 + t->pos;
      break;
    case UP:
      t->seq[0] = screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -screenWidth + t->pos;
      t->seq[3] = -2 * screenWidth + t->pos;
      break;
    case RIGHT:
      t->seq[0] = -1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = 1 + t->pos;
      t->seq[3] = 2 + t->pos;
      break;
  }
}

#define TETRO_INIT { \
  RIGHT, \
  400, \
  {0,400,0,0}, \
  tetro_rotate \
}

tetro *tetro_create() {
    tetro *p = malloc(sizeof(tetro));
    // p->o = DOWN;
    // p->pos = 400;
    // p->seq[0] = 0;
    // p->seq[1] = 400;
    // p->seq[2] = 0;
    // p->seq[3] = 0;
    // p->rotate = tetro_rotate;
    tetro temp = TETRO_INIT;
    memcpy(p, &temp, sizeof(tetro));
    return p;
}

void tetro_free(tetro *p) {
    free(p);
}
