
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
  enum tetro_type type;
  enum orientation o;
  int pos;
  int seq[4];
  void (*rotate)(struct tetro_t *t, int screenWidth);
} tetro;

tetro *tetro_create();
void tetro_free();
