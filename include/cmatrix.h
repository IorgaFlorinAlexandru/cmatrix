#ifndef CMATRIX_H
#define CMATRIX_H

#pragma once

#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

#define ANSI_HOME "\033[H"
#define ANSI_CLEAR "\033[0J"
#define ANSI_RESET "\x1b[0m"

#define BACKGROUND_BLACK "\x1b[48;5;232m"

// Classic Theme
#define COLOR_GREEN_100 "\x1b[38;2;0;255;0m"
#define COLOR_GREEN_200 "\x1b[38;2;22;229;14m"
#define COLOR_GREEN_300 "\x1b[38;2;30;204;21m"
#define COLOR_GREEN_400 "\x1b[38;2;35;179;24m"
#define COLOR_GREEN_500 "\x1b[38;2;36;155;26m"
#define COLOR_GREEN_600 "\x1b[38;2;36;131;26m"
#define COLOR_GREEN_700 "\x1b[38;2;34;108;25m"
#define COLOR_GREEN_800 "\x1b[38;2;32;86;23m"
#define COLOR_GREEN_900 "\x1b[38;2;28;65;21m"

static const char *classic_theme[] = {
  "\x1b[38;2;255;255;255m",   // WHITE
  "\x1b[38;2;0;255;0m",   // GREEN-100
  "\x1b[38;2;22;229;14m", // GREEN-200
  "\x1b[38;2;30;204;21m", // GREEN-300
  "\x1b[38;2;35;179;24m", // GREEN-400
  "\x1b[38;2;36;155;26m", // GREEN-500
  "\x1b[38;2;36;131;26m", // GREEN-600
  "\x1b[38;2;34;108;25m", // GREEN-700
  "\x1b[38;2;32;86;23m" , // GREEN-800
  "\x1b[38;2;28;65;21m",  // GREEN-900
  "\x1b[38;2;90;90;90m"   // GRAY
};

// Soviet Theme
#define COLOR_RED_100 "\x1b[38;2;255;0;0m"
#define COLOR_RED_200 "\x1b[38;2;230;15;4m"
#define COLOR_RED_300 "\x1b[38;2;205;22;7m"
#define COLOR_RED_400 "\x1b[38;2;180;26;9m"
#define COLOR_RED_500 "\x1b[38;2;156;28;10m"
#define COLOR_RED_600 "\x1b[38;2;133;28;11m"
#define COLOR_RED_700 "\x1b[38;2;111;27;11m"
#define COLOR_RED_800 "\x1b[38;2;89;25;10m"
#define COLOR_RED_900 "\x1b[38;2;68;22;9m"

#define COLOR_GRAY "\x1b[38;2;90;90;90m"

#endif

