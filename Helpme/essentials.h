#pragma once
#include <string>
#include <thread>

// задержка (хз зачем если есть Sleep, но я об этом узнал позже, так что лень удалять)
void sleep(int time);


enum ConsoleColor {
    Blue = 1,
    Green = 2,
    Aqua = 3,
    Red = 4,
    Purple = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LightBlue = 9,
    Black = 0,
    LightGreen = 10,
    LightAqua = 11,
    LightRed = 12,
    LightPurple = 13,
    LightYellow = 14,
    BrightWhite = 15
};


// установить цвет вывода, но с фоном
void setcolor(ConsoleColor color, ConsoleColor bg);

// установить цвет вывода
void setcolor(ConsoleColor color);

// сброс цвета вывода
void resetc();

// выводит текст посередине
void print_center(std::string text);

// принт побуквенно
void printCBC(std::string text, int delay);

// вывод лого игры :)
void printLogo();

// очищает вывод
void clear();

void play(std::string soundFile, bool sound);
//void stopSound();
//std::thread retry(std::string soundFile);


