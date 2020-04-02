#pragma once

enum orientation {
  DOWN = 1,
  LEFT,
  UP,
  RIGHT
};

enum tetro_type {
  LINE_BLOCK = 1,
  SQUARE_BLOCK,
  P_BLOCK,
  Z_BLOCK,
  L_BLOCK,
};

typedef struct tetro_t {
  enum orientation o;
  enum tetro_type type;
  int pos;
  int seq[4];
  void (*update)(struct tetro_t *t, int screenWidth);
} tetro;

tetro *tetro_create();
void tetro_free();
