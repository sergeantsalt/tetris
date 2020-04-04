
#include <string.h>
#include <stdlib.h>
#include "board.h"

static char *g_board;
static int len;

void board_create(int rows, int cols) {
  len = rows * cols;
  g_board = malloc(sizeof(char) * len);
  memset(g_board, 0, sizeof(char) * len);
}

void board_free() {
  free(g_board);
}

char *board_get() {
  return g_board;
}

int board_len() {
  return len;
}

void board_addToBoard(tetro *t, int screenCols) {
  g_board[t->seq[0]] = 1;
  g_board[t->seq[1]] = 1;
  g_board[t->seq[2]] = 1;
  g_board[t->seq[3]] = 1;
}

int board_collides(tetro *t) {
  int retVal = 0;
  if (t->seq[0] > len ||
    t->seq[1] > len ||
    t->seq[2] > len ||
    t->seq[3] > len) {
    retVal = 1;
  }

  for (int i = 0; i < len; i++) {
    if (g_board[i] &&
      (i == t->seq[0] || i == t->seq[1] ||
        i == t->seq[2] || i == t->seq[3] )) {
      retVal = 1;
    }
  }

  return retVal;
}

static void shiftRowsDown(int rows, int cols, int pos) {
  for (int i = (pos + cols - 1); i >= cols; i--) {
    g_board[i] = g_board[i - cols];
  }
}

void board_checkRowShift(int rows, int cols) {
  for (int i = (rows - 1); i > 0; i--) {
    int pos = i * cols;
    int streak = 0;
    for (int j = pos; j < (pos + cols); j++) {
      if (g_board[j] && streak == 0) {
        streak++;
      } else if (g_board[j] && streak > 0) {
        streak++;
      } else if (!g_board[j] && streak == 0) {
        continue;
      } else if (!g_board[j] && streak > 0) {
        break;
      }
    }

    if (streak >= 5) {
      shiftRowsDown(rows, cols, pos);
    }
  }
}