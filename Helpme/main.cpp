#include <iostream>
#include <conio.h>
#include <Windows.h> // Для взаимодействия с окном, цвето и тд
#include <cstdlib> // Для system()
#include "classes.h"
#include "essentials.h" // Вспомогательные методы
#include <thread>




using namespace std;


int main() {
    std::cout.sync_with_stdio(false);

    // добавляем русский
    setlocale(LC_ALL, "RU");


    // дстанавливаем название окна
    SetConsoleTitle(TEXT("ПОМОГИТЕ МЕНЯ ДЕРЖАТ В ЗАЛОЖНИКАХ"));


    // делаем размер окна неизменяемым
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    

    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX);
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 80, 30 });


    // определение классов (хз, не играл)

    Screen screen(menu);
    Settings settings;



    // первый вывод меню игры
    clear();
    printLogo();
    int choosed = 0;

    if (settings.getLang() == Russian) {
        cout << get_center("Новая игра - [+]") << "Новая игра - [+]" << endl;
        cout << get_center("Настройки - [ ]") << "Настройки - [ ]" << endl;
    }
    else {
        cout << get_center("New game - [+]") << "New game - [+]" << endl;
        cout << get_center("Settings - [ ]") << "Settings - [ ]" << endl;
    }



    // цикл обработки нажатий
    char ch;
    while (true) {

        if (_kbhit()) {
            ch = _getch();

            // если текущее состояние экрана это меню
            if (screen.getState() == menu) {
                switch (ch) {

                case 72:
                    if (choosed == 0) {
                        clear();
                        choosed++;
                        printLogo();
                        if (settings.getLang() == Russian) {
                            cout << get_center("Новая игра - [ ]") << "Новая игра - [ ]" << endl;
                            cout << get_center("Настройки - [+]") << "Настройки - [+]" << endl;
                        }
                        else {
                            cout << get_center("New game - [ ]") << "New game - [ ]" << endl;
                            cout << get_center("Settings - [+]") << "Settings - [+]" << endl;
                        }
                        break;
                    }
                    if (choosed == 1) {
                        clear();
                        // открыты настройки?
                        if (settings.is_opened() == true) {
                            // чек выбор настроек для отображения
                            switch (settings.get_chooseds()) {
                            case 0:
                                settings.set_chooseds(2);
                                printLogo();
                                settings.print_settings(settings);
                                break;
                            case 1:
                                settings.set_chooseds(0);
                                printLogo();
                                settings.print_settings(settings);
                                break;
                            case 2:
                                settings.set_chooseds(1);
                                printLogo();
                                settings.print_settings(settings);
                                break;
                            }
                            break;
                        }
                        choosed--;
                        printLogo();
                        if (settings.getLang() == Russian) {
                            cout << get_center("Новая игра - [+]") << "Новая игра - [+]" << endl;
                            cout << get_center("Настройки - [ ]") << "Настройки - [ ]" << endl;
                        }
                        else {
                            cout << get_center("New game - [+]") << "New game - [+]" << endl;
                            cout << get_center("Settings - [ ]") << "Settings - [ ]" << endl;
                        }
                        break;
                    }


                    break;
                case 80:
                    if (choosed == 0) {
                        clear();
                        choosed++;
                        printLogo();
                        if (settings.getLang() == Russian) {
                            cout << get_center("Новая игра - [ ]") << "Новая игра - [ ]" << endl;
                            cout << get_center("Настройки - [+]") << "Настройки - [+]" << endl;
                        }
                        else {
                            cout << get_center("New game - [ ]") << "New game - [ ]" << endl;
                            cout << get_center("Settings - [+]") << "Settings - [+]" << endl;
                        }
                        break;
                    }
                    else if (choosed == 1) {
                        clear();
                        if (settings.is_opened() == true) {
                            switch (settings.get_chooseds()) {
                            case 0:
                                settings.set_chooseds(1);
                                printLogo();
                                settings.print_settings(settings);
                                break;
                            case 1:
                                settings.set_chooseds(2);
                                printLogo();
                                settings.print_settings(settings);
                                break;
                            case 2:
                                settings.set_chooseds(0);
                                printLogo();
                                settings.print_settings(settings);
                                break;

                            }
                            break;
                            
                        }
                        choosed--;
                        printLogo();
                        if (settings.getLang() == Russian) {
                            cout << get_center("Новая игра - [+]") << "Новая игра - [+]" << endl;
                            cout << get_center("Настройки - [ ]") << "Настройки - [ ]" << endl;
                        }
                        else {
                            cout << get_center("New game - [+]") << "New game - [+]" << endl;
                            cout << get_center("Settings - [ ]") << "Settings - [ ]" << endl;
                        }
                        break;
                    }


                    break;

                case 13:
                    
                    if (choosed == 0) {

                    }

                    // при нажатии на энтер при выборе настроек в гл. меню
                    else if (choosed == 1) {

                        // проверить были открыты настройки или ноу
                        if (settings.is_opened() == false) {
                            settings.set_opened(true);
                            settings.set_chooseds(0);

                            
                            clear();
                            printLogo();
                            settings.print_settings(settings);
                            break;
                        }
                        else {
                            switch (settings.get_chooseds()) {
                            case 0:
                                clear();
                                printLogo();
                                if (settings.getLang() == Russian) {
                                    settings.changeLang(English);
                                    settings.print_settings(settings);
                                    break;
                                }
                                else {
                                    settings.changeLang(Russian);
                                    settings.print_settings(settings);
                                    break;
                                }
                            case 1:
                                clear();
                                printLogo();
                                if (settings.getLang() == English) {
                                    if (settings.getSounds() == true) {
                                        settings.changeSounds(false);
                                        settings.print_settings(settings);

                                    }
                                    else {
                                        settings.changeSounds(true);
                                        settings.print_settings(settings);

                                    }
                                    break;
                                }
                                else {
                                    if (settings.getSounds() == true) {
                                        settings.changeSounds(false);
                                        settings.print_settings(settings);
                                    }
                                    else {
                                        settings.changeSounds(true);
                                        settings.print_settings(settings);

                                    }

                                    break;
                                }
                            case 2:
                                clear();
                                printLogo();
                                settings.updateSettings();
                                settings.set_opened(false);
                                choosed = 0;

                                if (settings.getLang() == Russian) {
                                    cout << get_center("Новая игра - [+]") << "Новая игра - [+]" << endl;
                                    cout << get_center("Настройки - [ ]") << "Настройки - [ ]" << endl;
                                }
                                else {
                                    cout << get_center("New game - [+]") << "New game - [+]" << endl;
                                    cout << get_center("Settings - [ ]") << "Settings - [ ]" << endl;
                                }
                                break;
                            }
                        }
                        



                    }
                }
            }

            
        }
    }
}

