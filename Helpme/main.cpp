
#include <conio.h>
#include <Windows.h>
#include "classes.h"
#include "essentials.h"
#include <thread>




int main() {


    // добавляем русский
    setlocale(LC_ALL, "RU");


    // устанавливаем название окна
    SetConsoleTitle(TEXT("Dungeon"));


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
        print_center(Russian_loc["newgame"] + " - [+]");
        print_center(Russian_loc["settings"] + " - [ ]");
    }
    else {
        print_center(English_loc["newgame"] + " - [+]");
        print_center(English_loc["settings"] + " - [ ]");
    }



    // цикл обработки нажатий
    char ch;
    while (true) {

        if (_kbhit()) {
            ch = _getch();

            // если текущее состояние экрана это меню
            if (screen.getState() == menu) {
                switch (ch) {

                // стрелочка вверх
                case ArrowUp:
                    if (choosed == 0) {
                        clear();
                        choosed++;
                        printLogo();
                        if (settings.getLang() == Russian) {
                            print_center(Russian_loc["newgame"] + " - [ ]");
                            print_center(Russian_loc["settings"] + " - [+]");
                        }
                        else {
                            print_center(English_loc["newgame"] + " - [ ]");
                            print_center(English_loc["settings"] + " - [+]");
                        }
                        break;
                    }
                    if (choosed == 1) {
                        clear();
                        // открыты настройки?
                        if (settings.is_opened()) {
                            // чек выбор настроек для отображения
                            printLogo();
                            switch (settings.get_chooseds()) {
                            case 0:
                                settings.set_chooseds(2);
                                settings.print_settings(settings);
                                break;
                            case 1:
                                settings.set_chooseds(0);
                                settings.print_settings(settings);
                                break;
                            case 2:
                                settings.set_chooseds(1);
                                settings.print_settings(settings);
                                break;
                            }
                            break;
                        }
                        choosed--;
                        printLogo();
                        std::map<std::string, std::string> loc = get_loc[settings.getLang()];

                        print_center(loc["newgame"] + " - [+]");
                        print_center(loc["settings"] + " - [ ]");
                        break;
                    }


                    break;
                // стрелочка вниз
                case ArrowDown:
                    if (choosed == 0) {
                        clear();
                        choosed++;
                        printLogo();
                        std::map<std::string, std::string> loc = get_loc[settings.getLang()];
                        print_center(loc["newgame"] + " - [ ]");
                        print_center(loc["settings"] + " - [+]");

                        break;
                    }
                    else if (choosed == 1) {
                        clear();
                        if (settings.is_opened()) {
                            printLogo();
                            switch (settings.get_chooseds()) {
                            case 0:
                                settings.set_chooseds(1);
                                settings.print_settings(settings);
                                break;
                            case 1:
                                settings.set_chooseds(2);
                                settings.print_settings(settings);
                                break;
                            case 2:
                                settings.set_chooseds(0);
                                settings.print_settings(settings);
                                break;

                            }
                            break;
                            
                        }
                        choosed--;
                        printLogo();
                        std::map<std::string, std::string> loc = get_loc[settings.getLang()];
                        print_center(loc["newgame"] + " - [+]");
                        print_center(loc["settings"] + " - [ ]");


                        break;
                    }


                    break;

                // Enter
                case Enter:
                    
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
                            clear();
                            printLogo();
                            switch (settings.get_chooseds()) {
                            case 0:
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
                                if (settings.getSounds()) {
                                    settings.changeSounds(false);
                                    settings.print_settings(settings);

                                }
                                else {
                                    settings.changeSounds(true);
                                    settings.print_settings(settings);

                                }
                                break;
                                
                            case 2:

                                settings.updateSettings();
                                settings.set_opened(false);
                                choosed = 0;

                                std::map<std::string, std::string> loc = get_loc[settings.getLang()];

                                print_center(loc["newgame"] + " - [+]");
                                print_center(loc["settings"] + " - [ ]");
                                break;
                            }
                        }
                    }
                }
            } 
        }
    }
}

