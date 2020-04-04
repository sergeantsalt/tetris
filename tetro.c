#include "tetro.h"

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

void tetro_lineRotate(tetro *t, int screenWidth) {
  if (t->o > RIGHT) {
    t->o = DOWN;
  }

  switch (t->o) {
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

void tetro_squareRotate(tetro *t, int screenWidth) {
  t->seq[0] = -1 + t->pos;
  t->seq[1] = t->pos;
  t->seq[2] = screenWidth + t->pos;
  t->seq[3] = -1 + screenWidth + t->pos;
}

void tetro_pRotate(tetro *t, int screenWidth) {
  if (t->o > RIGHT) {
    t->o = DOWN;
  }

  switch (t->o) {
    case DOWN:
      t->seq[0] = -1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = 1 + t->pos;
      t->seq[3] = screenWidth + t->pos;
      break;
    case LEFT:
      t->seq[0] = -screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = screenWidth + t->pos;
      t->seq[3] = -1 + t->pos;
      break;
    case UP:
      t->seq[0] = 1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -1 + t->pos;
      t->seq[3] = -screenWidth + t->pos;
      break;
    case RIGHT:
      t->seq[0] = screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -screenWidth + t->pos;
      t->seq[3] = 1 + t->pos;
      break;
  }
}

void tetro_zRotate(tetro *t, int screenWidth) {
  if (t->o > RIGHT) {
    t->o = DOWN;
  }

  switch (t->o) {
    case DOWN:
      t->seq[0] = -screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = 1 + t->pos;
      t->seq[3] = 1 + screenWidth + t->pos;
      break;
    case LEFT:
      t->seq[0] = 1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = screenWidth + t->pos;
      t->seq[3] = -1 + screenWidth + t->pos;
      break;
    case UP:
      t->seq[0] = screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -1 + t->pos;
      t->seq[3] = -1 + -screenWidth + t->pos;
      break;
    case RIGHT:
      t->seq[0] = -1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -screenWidth + t->pos;
      t->seq[3] = 1 + -screenWidth + t->pos;
      break;
  }
}

void tetro_lRotate(tetro *t, int screenWidth) {
  if (t->o > RIGHT) {
    t->o = DOWN;
  }

  switch (t->o) {
    case DOWN:
      t->seq[0] = -screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = screenWidth + t->pos;
      t->seq[3] = 1 + screenWidth + t->pos;
      break;
    case LEFT:
      t->seq[0] = 1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -1 + t->pos;
      t->seq[3] = -1 + screenWidth + t->pos;
      break;
    case UP:
      t->seq[0] = screenWidth + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = -screenWidth + t->pos;
      t->seq[3] = -1 + -screenWidth + t->pos;
      break;
    case RIGHT:
      t->seq[0] = -1 + t->pos;
      t->seq[1] = t->pos;
      t->seq[2] = 1 + t->pos;
      t->seq[3] = 1 + -screenWidth + t->pos;
      break;
  }
}

#define TETRO_INIT \
  { DOWN, 0, 400, {0, 400, 0, 0}, NULL }

tetro *tetro_create() {
  struct timeval start;
  gettimeofday(&start, NULL);
  int type = start.tv_usec % 3 + 1;

  tetro *p = malloc(sizeof(tetro));
  tetro temp = TETRO_INIT;
  memcpy(p, &temp, sizeof(tetro));
  p->type = type;
  switch (p->type) {
    case LINE_BLOCK: p->update = tetro_lineRotate; break;
    case SQUARE_BLOCK: p->update = tetro_squareRotate; break;
    case P_BLOCK: p->update = tetro_pRotate; break;
    case Z_BLOCK: p->update = tetro_zRotate; break;
    case L_BLOCK: p->update = tetro_lRotate; break;
  }
  return p;
}

void tetro_free(tetro *p) { free(p); }
