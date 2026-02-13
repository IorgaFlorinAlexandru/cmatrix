#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include "cloud.h"

//#define RED "\033[31m"
//#define GREEN "\033[32m"
//#define YELLOW "\033[33m"
//#define BLUE "\033[34m"
//#define RESET "\033[0m"

#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

const static int DEBUG_TIME = 100*1000;
const static int SLEEP_TIME = 66*1000;

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

int main() {
  int rows, cols;
  if(get_terminal_size(&rows, &cols) != 0) {
    printf("Failed to acquire terminal size\n");
    return 0;
  }
  srand(time(NULL));
  Cloud *c = initialize_cloud(rows,cols);
  printf(HIDE_CURSOR);
  
  signal(SIGINT, on_sigint);
  while(isRaining) {
    rain(c);
    usleep(DEBUG_TIME);
  }

  printf(SHOW_CURSOR);
  system("clear");

  return 0;
}
