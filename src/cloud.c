#include "cloud.h"
#include "droplet.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_CLEAR "\033[0J"
#define ANSI_HOME "\033[H"

void rain(Cloud *c) {
  static unsigned int tick = 1;

  printf(ANSI_CLEAR ANSI_HOME);
  draw_grid(c); // for colors i could use another array to keep what color to use in that position
  fflush(stdout);

  for(size_t i = 0; i < c->cols; i++) {
    advance_droplet(&c->droplets[i], c->rows,c->grid,tick);
  }
  tick++;
}

Cloud* initialize_cloud(int rows,int cols) {
  Cloud *c = malloc(sizeof *c);
  c->rows = rows-1;
  c->cols = cols;
  c->grid = construct_grid(rows-1,cols);

  c->droplets = malloc(c->cols * sizeof *c->droplets);
  for(size_t i = 0; i < c->cols; i++) {
    c->droplets[i] = *create_droplet(i);
  }

  return c;
}

void draw_grid(Cloud *c) {
  for(size_t i = 0; i < c->rows; i++) {
    printf("%s\n", c->grid[i]);
  }
}

// setting grid[n][cols+10] does not trigger a segmentation fault, why?
char** construct_grid(int rows,int cols) {
  char **grid = malloc(rows * sizeof(*grid));
  for(size_t i = 0; i < rows; i++) {
    grid[i] = malloc(cols);
    memset(grid[i], ' ', cols);
    grid[i][cols] = '\0';
  }

  return grid;
}
