#include "droplet.h"
#include <stdlib.h>

const int MAX_LENGTH = 5;
const int MIN_LENGTH = 3;

static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

static char random_char() {
  return charset[rand() % 62];
}

void advance_droplet(Droplet *droplet, char **grid,int tick) {
  //Speed
  if(tick%droplet->speed != 0) {
    return;
  }

  //Tail action
  if(droplet->head-droplet->length >= 0) {
    grid[droplet->head-droplet->length][droplet->boundCol] = ' ';
  }

  //Move action
  if(droplet->head < droplet->endLine) {
    grid[droplet->head][droplet->boundCol] = random_char();
    droplet->head++;
  }
  else {
    droplet->length--;
  }

  droplet->isAlive = !(droplet->length == 0);
}

Droplet* create_droplet(int col, int rows) {
  Droplet *d = malloc(sizeof *d);
  d->isAlive = true;
  d->head = 0;
  d->tail = 0;
  d->length = (rand() % MAX_LENGTH) + MIN_LENGTH;
  d->boundCol = col;
  d->endLine = rows;
  d->speed = (rand() % 3) + 1;
  return d;
}

void reset(Droplet *d) {
  d->head = 0;
  d->tail = 0;
  d->length = (rand() % MAX_LENGTH) + MIN_LENGTH;
  d->speed = (rand() % 3) + 1;
  d->isAlive = true;
}
