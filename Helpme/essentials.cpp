#include "essentials.h"
#include <chrono>   // Для использования std::chrono::milliseconds
#include <thread>   // Для использования std::this_thread::sleep_for
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // необходимо для подключения библиотеки winmm.lib

using namespace std;

#include <string>

HANDLE hConsole;

// здесь был асинхронное проигрывания звука на фоне (типа музика)
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
*/
void play(string soundFile, bool sound)
{
    if (!sound) return;
    std::wstring wideSoundFile;
    wideSoundFile.resize(soundFile.size());
    MultiByteToWideChar(CP_UTF8, 0, soundFile.c_str(), soundFile.size(), &wideSoundFile[0], soundFile.size());


    PlaySound(wideSoundFile.c_str(), NULL, SND_FILENAME | SND_ASYNC);

    
}


// задержка (хз зачем если есть Sleep, но я об этом узнал позже, так что лень удалять)
void sleep(int time) {
	this_thread::sleep_for(chrono::milliseconds(time * 1000));
}

// установить цвет вывода, но с фоном
void setcolor(ConsoleColor text, ConsoleColor background) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
}

// установить цвет вывода
void setcolor(ConsoleColor color) {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

// сброс цвета вывода
void resetc() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7 | 0);
}


// возвращает пробелы которые нужны для вывода текста посередине экрана с учетом размеров окна
void print_center(string text) {
    int width = 80; // Ширина консоли по умолчанию
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Получаем ширину консоли
    }
    int padding = (width - text.length()) / 2; // Вычисляем отступ слева
    string result;
    for (int i = 0; i < padding; i++) {
        result += " "; // Добавляем отступ слева в результат
    }
    cout << result << text << endl;
}


// принт побуквенно
void printCBC(string text, int delay) {
    for (char c : text) {
        putchar(c);
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

// вывод лого игры :)
void printLogo() {
    std::cout.sync_with_stdio(false);
    cout << endl << endl;

    print_center("`7MM\"\"\"Yb.                                                                    ");
    print_center("  MM    `Yb.                                                                  ");
    print_center("  MM     `Mb `7MM  `7MM  `7MMpMMMb.   .P\"Ybmmm  .gP\"Ya   ,pW\"Wq.  `7MMpMMMb.  ");
    print_center("  MM      MM   MM    MM    MM    MM  :MI  I8   ,M'   Yb 6W'   `Wb   MM    MM  ");
    print_center("  MM     ,MP   MM    MM    MM    MM   WmmmP\"   8M\"\"\"\"\"\" 8M     M8   MM    MM  ");
    print_center("  MM    ,dP'   MM    MM    MM    MM  8M        YM.    , YA.   ,A9   MM    MM  ");
    print_center(".JMMmmmdP'     `Mbod\"YML..JMML  JMML. YMMMMMb   `Mbmmd'  `Ybmd9'  .JMML  JMML.");
    print_center("                                     6'     dP                                ");
    print_center("                                     Ybmmmd'                                  ");
    cout << endl << endl << endl;
}

// очищает вывод
void clear() {
    //system("cls");
    // cout << "\033[2J\033[1;1H";

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    DWORD charsWritten;

    GetConsoleScreenBufferInfo(hOut, &screenBufferInfo);
    FillConsoleOutputCharacter(hOut, ' ', screenBufferInfo.dwSize.X * screenBufferInfo.dwSize.Y, coord, &charsWritten);
    SetConsoleCursorPosition(hOut, coord);
}