#pragma once
#include <ncurses.h> // Ncurses library
#include <string>

class Ncursed {
  int height;
  int width;

public:
  Ncursed() { init(); }

  void init() {
    setlocale(LC_ALL, ""); // Enable Unicode support
    initscr();             // Start ncurses mode
    // Get terminal size
    getmaxyx(stdscr, height, width);
    noecho();                          // Don't echo input
    cbreak();                          // Disable line buffering
    curs_set(0);                       // Hide the cursor
    keypad(stdscr, TRUE);              // enable keypad for special keys
    mousemask(ALL_MOUSE_EVENTS, NULL); // enable mouse events
    start_color(); // enable colors in ncurses
  }

  string getHeight() { return std::to_string(height); }
  string getWidth() { return std::to_string(width); }
};
