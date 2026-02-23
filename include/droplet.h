#ifndef DROPLET_H
#define DROPLET_H

#pragma once

#include <stdint.h>

// for colors i could use another array to keep what color to use in that position
typedef struct {
  int length;
  int head;
  int tail;
  unsigned int pos;
  uint8_t speed;
} Droplet;

void advance_droplet(Droplet *droplet, int rows, char **grid, int tick);
Droplet* create_droplet(int cols);

#endif
