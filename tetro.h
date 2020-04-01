
enum orientation {
  DOWN = 1,
  LEFT,
  UP,
  RIGHT
};

typedef struct tetro_t {
  enum orientation o;
  int pos;
  int seq[4];
  void (*rotate)(struct tetro_t *t, int screenWidth);
} tetro;

tetro *tetro_create();
void tetro_free();
