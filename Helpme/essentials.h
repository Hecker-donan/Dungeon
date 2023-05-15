#pragma once
#include <string>
#include <thread>

// �������� (�� ����� ���� ���� Sleep, �� � �� ���� ����� �����, ��� ��� ���� �������)
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


// ���������� ���� ������, �� � �����
void setcolor(ConsoleColor color, ConsoleColor bg);

// ���������� ���� ������
void setcolor(ConsoleColor color);

// ����� ����� ������
void resetc();

// ������� ����� ����������
void print_center(std::string text);

// ����� ����������
void printCBC(std::string text, int delay);

// ����� ���� ���� :)
void printLogo();

// ������� �����
void clear();

void play(std::string soundFile, bool sound);
//void stopSound();
//std::thread retry(std::string soundFile);


