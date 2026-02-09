#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include "cmatrix.h"
#include "cloud.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

const int DEBUG_TIME = 100*1000;

int get_terminal_size(int *row, int *col) {
  struct winsize ws;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0 && ws.ws_col > 0 && ws.ws_row > 0) {
    *row = ws.ws_row;
    *col = ws.ws_col;
    return 0;
  }

  return -1;
}

int main() {
  int rows, cols;
  if(get_terminal_size(&rows, &cols) != 0) {
    printf("Failed to acquire terminal size\n");
    return 0;
  }

  srand(time(NULL));

  Cloud *c = initialize_cloud(rows,cols);
  c->grid[rows-2][2] = '1';
  printf(HIDE_CURSOR);
  int t = 0, i = 0;
  while(t < 30) {
    printf(ANSI_CLEAR ANSI_HOME);
    draw_grid(c);
    fflush(stdout);
    rain(c);
    t++;

    usleep(DEBUG_TIME);
  }

  printf(SHOW_CURSOR);
  system("clear");

  return 0;
}
