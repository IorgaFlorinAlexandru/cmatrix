#include "cloud.h"
#include "droplet.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int DROPLETS_SIZE = 5;

void rain(Cloud *c) {
  for(size_t i = 0; i < DROPLETS_SIZE; i++) {
    advance_droplet(&c->droplets[i], c->rows,c->cols, c->grid);
  }
}

Cloud* initialize_cloud(int rows,int cols) {
  Cloud *c = malloc(sizeof *c);
  c->rows = rows-1;
  c->cols = cols;
  c->grid = construct_grid(rows-1,cols);

  c->droplets = malloc(DROPLETS_SIZE * sizeof *c->droplets);
  for(size_t i = 0; i < DROPLETS_SIZE; i++) {
    c->droplets[i] = *create_droplet(cols);
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
