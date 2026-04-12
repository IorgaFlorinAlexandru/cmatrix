#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include "cloud.h"
#include "cmatrix.h"

const static int DEBUG_TIME = 100000;
const static int SLEEP_TIME = 33000;

static volatile sig_atomic_t isRaining = 1;

static void on_sigint(int sig) {
  (void)sig;
  isRaining = 0;
}

static int get_terminal_size(int *row, int *col) {
  struct winsize ws;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0 && ws.ws_col > 0 && ws.ws_row > 0) {
    *row = ws.ws_row;
    *col = ws.ws_col;
    return 0;
  }

  return -1;
}

//TODO: Free Memory
static void cleanup() {
  printf(SHOW_CURSOR);
  printf(ANSI_RESET);
  fflush(stdout);
  system("clear");
}

int main() {
  int rows, cols;
  if(get_terminal_size(&rows, &cols) != 0) {
    printf("Failed to acquire terminal size\n");
    return 0;
  }

  srand(time(NULL));
  signal(SIGINT, on_sigint);

  system("clear");
  Cloud *c = initialize_cloud(rows,cols);
  printf(HIDE_CURSOR);
  unsigned int tick = 1;
  while(isRaining) {
    rain(c,tick);
    usleep(DEBUG_TIME);
    tick++;
  }
  cleanup();

  return 0;
}
