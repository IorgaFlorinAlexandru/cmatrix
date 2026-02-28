#include "cloud.h"
#include "cmatrix.h"
#include "droplet.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void draw_grid(Cloud *c) {
  printf(ANSI_CLEAR ANSI_HOME);
  printf(BACKGROUND_BLACK COLOR_GREEN_100); 
  for(size_t i = 0; i < c->rows; i++) {
    printf("%s", c->grid[i]);
  }
  printf(ANSI_RESET);
  // Might be worth to have a buffer then fwrite it all
  //for(size_t i = 0; i < c->rows; i++) {
  //  for(size_t j = 0; j < c->cols; j++) {
  //    Droplet d = c->droplets[j];
  //    if(d.head-1 == i) {
  //      printf("%s", classic_theme[0]);
  //    }
  //    else {
  //      printf("%s", classic_theme[1]);
  //    }
  //    printf("%c", c->grid[i][j]);
  //  }
  //}
  fflush(stdout);
}

// setting grid[n][cols+10] does not trigger a segmentation fault, why?
static char** construct_grid(int rows,int cols) {
  char **grid = malloc(rows * sizeof(*grid));
  for(size_t i = 0; i < rows; i++) {
    grid[i] = malloc(cols);
    memset(grid[i], ' ', cols);
    grid[i][cols] = '\0';
  }

  return grid;
}

void rain(Cloud *c) {
  static unsigned int tick = 1;
  draw_grid(c); 
  for(size_t i = 0; i < c->cols; i++) {
    if(c->droplets[i].isAlive) {
      advance_droplet(&c->droplets[i],c->grid,tick);
    }
    else {
      reset(&c->droplets[i]);
    }
  }
  tick++;
}

Cloud* initialize_cloud(int rows,int cols) {
  Cloud *c = malloc(sizeof *c);
  c->rows = rows;
  c->cols = cols;
  c->grid = construct_grid(rows,cols);

  c->droplets = malloc(c->cols * sizeof *c->droplets);
  for(size_t i = 0; i < cols; i++) {
    c->droplets[i] = *create_droplet(i,rows);
  }

  return c;
}


