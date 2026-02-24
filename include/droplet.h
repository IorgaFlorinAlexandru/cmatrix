#ifndef DROPLET_H
#define DROPLET_H

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  bool isAlive;
  int length;
  int head;
  int tail;
  unsigned int boundCol;
  unsigned int endLine;
  uint8_t speed;
} Droplet;

void advance_droplet(Droplet *droplet, char **grid, int tick);
Droplet* create_droplet(int col, int rows);
void reset(Droplet *droplet);
void activate(Droplet *droplet);

#endif
