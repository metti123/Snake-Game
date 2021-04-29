
#include "Screen.h"


const char *msgs[] = {
    "",
    "Failed GetStdHandle(): INVALID_HANDLE_VALUE",
    "Failed GetConsoleCursorInfo()",
    "Failed SetConsoleCursorInfo()",
    "Failed SetConsoleCursorPosition()"
};

const char *ScreenException::what() {
    return msgs[err];
}

Screen::Screen() {
    initscr();
    start_color();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, true);
}

Screen::~Screen() {
    nodelay(stdscr, false);
    curs_set(1);
    echo();
    keypad(stdscr, FALSE);
    noraw();
    endwin();
}

void Screen::text_attr(short attr) {
    short fg = attr & 0x000f;
    short bg = (attr & 0x00f0) >> 4;
    init_pair(1, fg, bg);
    attrset(COLOR_PAIR(1));
}
