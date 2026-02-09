#ifndef DROPLET_H
#define DROPLET_H

#pragma once

typedef enum {
  SLOW,
  NORMAL,
  FAST
} Speed;

// SPEED, POS,
typedef struct {
  int length;
  int head;
  int tail;
  int pos;
  Speed speed;
} Droplet;


void advance_droplet(Droplet *droplet, int rows, int cols, char **grid);
Droplet* create_droplet(int cols);

#endif
