#include "essentials.h"
#include <chrono>   // ��� ������������� std::chrono::milliseconds
#include <thread>   // ��� ������������� std::this_thread::sleep_for
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // ���������� ��� ����������� ���������� winmm.lib

using namespace std;

#include <string>

HANDLE hConsole;

// ����� ��� ����������� ������������ ����� �� ���� (���� ������)
/*
thread retry(string soundFile) {
    isPlaying = true;
    thread soundThread(playSound, soundFile);
    return soundThread;
}

void stopSound()
{
    isPlaying = false;
    // PlaySound(NULL, NULL, 0);
}

void playSound(string soundFile)
{
    std::wstring wideSoundFile;
    wideSoundFile.resize(soundFile.size());
    MultiByteToWideChar(CP_UTF8, 0, soundFile.c_str(), soundFile.size(), &wideSoundFile[0], soundFile.size());


    PlaySound(wideSoundFile.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


    while (isPlaying) {
        Sleep(100);
    }
    PlaySound(NULL, NULL, 0);
    
}
*/

// �������� (�� ����� ���� ���� Sleep, �� � �� ���� ����� �����, ��� ��� ���� �������)
void sleep(int time) {
	this_thread::sleep_for(chrono::milliseconds(time * 1000));
}

// ���������� ���� ������, �� � �����
void setcolor(ConsoleColor text, ConsoleColor background) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
}

// ���������� ���� ������
void setcolor(ConsoleColor color) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

// ����� ����� ������
void resetc() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7 | 0);
}


// ���������� ������� ������� ����� ��� ������ ������ ���������� ������ � ������ �������� ����
string get_center(string text) {
    int width = 80; // ������ ������� �� ���������
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // �������� ������ �������
    }
    int padding = (width - text.length()) / 2; // ��������� ������ �����
    string result;
    for (int i = 0; i < padding; i++) {
        result += " "; // ��������� ������ ����� � ���������
    }
    return result;
}


// ����� ����������
void printCBC(string text, int delay) {
    for (char c : text) {
        putchar(c);
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

// ����� ���� ���� :)
void printLogo() {
    std::cout.sync_with_stdio(false);
    cout << endl << endl;

    cout << get_center("`7MM\"\"\"Yb.                                                                    ") <<     "`7MM\"\"\"Yb.                                                                    " << endl;
    cout << get_center("  MM    `Yb.                                                                  ") <<        "  MM    `Yb.                                                                  " << endl;
    cout << get_center("  MM     `Mb `7MM  `7MM  `7MMpMMMb.   .P\"Ybmmm  .gP\"Ya   ,pW\"Wq.  `7MMpMMMb.  ") <<       "  MM     `Mb `7MM  `7MM  `7MMpMMMb.   .P\"Ybmmm  .gP\"Ya   ,pW\"Wq.  `7MMpMMMb.  " << endl;
    cout << get_center("  MM      MM   MM    MM    MM    MM  :MI  I8   ,M'   Yb 6W'   `Wb   MM    MM  ") <<        "  MM      MM   MM    MM    MM    MM  :MI  I8   ,M'   Yb 6W'   `Wb   MM    MM  " << endl;
    cout << get_center("  MM     ,MP   MM    MM    MM    MM   WmmmP\"   8M\"\"\"\"\"\" 8M     M8   MM    MM  ") << "  MM     ,MP   MM    MM    MM    MM   WmmmP\"   8M\"\"\"\"\"\" 8M     M8   MM    MM  " << endl;
    cout << get_center("  MM    ,dP'   MM    MM    MM    MM  8M        YM.    , YA.   ,A9   MM    MM  ") <<        "  MM    ,dP'   MM    MM    MM    MM  8M        YM.    , YA.   ,A9   MM    MM  " << endl;
    cout << get_center(".JMMmmmdP'     `Mbod\"YML..JMML  JMML. YMMMMMb   `Mbmmd'  `Ybmd9'  .JMML  JMML.") <<          ".JMMmmmdP'     `Mbod\"YML..JMML  JMML. YMMMMMb   `Mbmmd'  `Ybmd9'  .JMML  JMML." << endl;
    cout << get_center("                                     6'     dP                                ") <<        "                                     6'     dP                                " << endl;
    cout << get_center("                                     Ybmmmd'                                  ") <<        "                                     Ybmmmd'                                  " << endl << endl;
    cout << endl;
}

// ������� �����
void clear() {
    cout << "\033[2J\033[1;1H";
}