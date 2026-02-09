#include "droplet.h"
#include <stdlib.h>

const int MAX_LENGTH = 7;
const int MIN_LENGTH = 2;

void advance_droplet(Droplet *droplet, int rows, int cols, char **grid) {
  //End action
  if(droplet->length == 0) {
    return;
  }

  //Tail action
  if(droplet->head-droplet->length >= 0) {
    grid[droplet->head-droplet->length][droplet->pos] = ' ';
  }

  //Move action
  if(droplet->head < rows) {
    grid[droplet->head][droplet->pos] = '1';
    droplet->head++;
  }
  else {
    droplet->length--;
  }
}

Droplet* create_droplet(int cols) {
  Droplet *d = malloc(sizeof *d);
  d->head = 0;
  d->tail = 0;
  d->length = (rand() % MAX_LENGTH) + MIN_LENGTH;
  d->pos = rand() % cols;
  return d;
}
