#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include "cloud.h"
#include "cmatrix.h"

const static int DEBUG_TIME = 100*1000;
const static int SLEEP_TIME = 33*1000;

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

static void cleanup() {
  printf(SHOW_CURSOR);
  printf(ANSI_RESET);
  fflush(stdout);
  system("clear");
}

static void testGreenTheme() {
  printf(BACKGROUND_BLACK); 
  printf("1");
  printf(COLOR_GREEN_100);
  printf("1");
  printf(COLOR_GREEN_200);
  printf("1");
  printf(COLOR_GREEN_300);
  printf("1");
  printf(COLOR_GREEN_400);
  printf("1");
  printf(COLOR_GREEN_500);
  printf("1");
  printf(COLOR_GREEN_600);
  printf("1");
  printf(COLOR_GREEN_700);
  printf("1");
  printf(COLOR_GREEN_800);
  printf("1");
  printf(COLOR_GREEN_900);
  printf("1");
  printf(COLOR_GRAY);
  printf("1");
  printf("\n");
  printf(ANSI_RESET);
}
static void testRedTheme() {
  printf(BACKGROUND_BLACK); 
  printf("1");
  printf(COLOR_RED_100);
  printf("1");
  printf(COLOR_RED_200);
  printf("1");
  printf(COLOR_RED_300);
  printf("1");
  printf(COLOR_RED_400);
  printf("1");
  printf(COLOR_RED_500);
  printf("1");
  printf(COLOR_RED_600);
  printf("1");
  printf(COLOR_RED_700);
  printf("1");
  printf(COLOR_RED_800);
  printf("1");
  printf(COLOR_RED_900);
  printf("1");
  printf(COLOR_GRAY);
  printf("1");
  printf("\n");
}

int main() {
  testGreenTheme();
  testRedTheme();
  return 0;

  int rows, cols;
  if(get_terminal_size(&rows, &cols) != 0) {
    printf("Failed to acquire terminal size\n");
    return 0;
  }
  srand(time(NULL));
  signal(SIGINT, on_sigint);

  Cloud *c = initialize_cloud(rows,cols);
  printf(BACKGROUND_BLACK COLOR_GREEN_100); 
  printf(HIDE_CURSOR);
  while(isRaining) {
    rain(c);
    usleep(DEBUG_TIME);
  }
  cleanup();

  return 0;
}
