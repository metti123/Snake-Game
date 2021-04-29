
#ifndef __SCREEN_H__
#define __SCREEN_H__


#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif // _WIN32

class ScreenException {
public:
    ScreenException(int _err) : err(_err) {}
    const char *what();
    int err;
};

#define printf printw

class Screen {
public:
    Screen();
    ~Screen();
    void text_attr(short attr);
private:
};


#endif // __SCREEN_H__
