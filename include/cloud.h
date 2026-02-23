#ifndef CLOUD_H
#define CLOUD_H

#pragma once

#include "droplet.h"

typedef struct {
  Droplet *droplets;
  int rows;
  int cols;
  char **grid;
} Cloud;

Cloud* initialize_cloud(int rows, int cols);
void rain(Cloud *c);

#endif
