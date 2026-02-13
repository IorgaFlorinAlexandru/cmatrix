#ifndef DROPLET_H
#define DROPLET_H

#pragma once

// SPEED, POS,
typedef struct {
  int length;
  int head;
  int tail;
  int pos;
  int speed;
} Droplet;

void advance_droplet(Droplet *droplet, int rows, char **grid, int tick);
Droplet* create_droplet(int cols);

#endif
