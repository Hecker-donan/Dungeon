#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "classes.h"



Screen::Screen(states state) {
    this->state = state;
}

void Screen::changeState(states state) {
    this->state = state;
}

states Screen::getState() {
    return this->state;
}




// изменить язык игры
void Settings::changeLang(Languages lang)
{
    this->lang = lang;
}

// узнать язык игры
Languages Settings::getLang()
{
    return this->lang;
}


// установить звуки включенными или нет
void Settings::changeSounds(bool music)
{
    this->sounds = music;
}

// узнать, включены звуки или нет
bool Settings::getSounds()
{
    return this->sounds;
}

// установить, открыты настройки или нет
void Settings::set_opened(bool arg)
{
    this->opened = arg;
}

// узнать открыты настройки или нет
bool Settings::is_opened()
{
    return this->opened;
}

// возвращает порядкоый номер выбора в настройках
void Settings::set_chooseds(int arg)
{
    this->chooseds = arg;
}

// изменяет текущий порядковый номер выбора в настройках
int Settings::get_chooseds()
{
    return this->chooseds;
}


// обновление файла настроек новыми значениями из this
void Settings::updateSettings() 
{
    remove("settings.cfg");
    std::ofstream file("settings.cfg");
    if (this->lang == Russian) {
        file << "lang=rus" << std::endl;
    }
    else {
        file << "lang=eng" << std::endl;
    }

    if (this->sounds == true) {
        file << "sounds=true" << std::endl;
    }
    else {
        file << "sounds=false" << std::endl;
    }
    
    
    file.close();

}


std::string get_centerr(std::string text) {
    int width = 80; // Ширина консоли по умолчанию
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Получаем ширину консоли
    }
    int padding = (width - text.length()) / 2; // Вычисляем отступ слева
    std::string result;
    for (int i = 0; i < padding; i++) {
        result += " "; // Добавляем отступ слева в результат
    }
    return result;
}

// выводит настройки для главного меню в зависимости от самих настроек
void Settings::print_settings(Settings& settings) {
    std::ios::sync_with_stdio(false);

    if (settings.getLang() == Russian) {
        switch (settings.get_chooseds()) {
        case 0:
            std::cout << get_centerr(">Язык - Русский") << ">Язык - Русский" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr("Звуки - Включены") << "Звуки - Включены" << std::endl;

            }
            else {
                std::cout << get_centerr("Звуки - Выключены") << "Звуки - Выключены" << std::endl;

            }

            std::cout << get_centerr("Назад") << "Назад" << std::endl;
            break;
        case 1:
            std::cout << get_centerr("Язык - Русский") << "Язык - Русский" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr(">Звуки - Включены") << ">Звуки - Включены" << std::endl;

            }
            else {
                std::cout << get_centerr(">Звуки - Выключены") << ">Звуки - Выключены" << std::endl;

            }

            std::cout << get_centerr("Назад") << "Назад" << std::endl;
            break;
        case 2:
            std::cout << get_centerr("Язык - Русский") << "Язык - Русский" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr("Звуки - Включены") << "Звуки - Включены" << std::endl;

            }
            else {
                std::cout << get_centerr("Звуки - Выключены") << "Звуки - Выключены" << std::endl;

            }

            std::cout << get_centerr(">Назад") << ">Назад" << std::endl;
        }


    }
    else {
        switch (settings.get_chooseds()) {
        case 0:
            std::cout << get_centerr(">Lang - English") << ">Lang - English" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr("Sounds - Enabled") << "Sounds - Enabled" << std::endl;

            }
            else {
                std::cout << get_centerr("Sounds - Disabled") << "Sounds - Disabled" << std::endl;

            }
            std::cout << get_centerr("Back") << "Back" << std::endl;
            break;
        case 1:
            std::cout << get_centerr("Lang - English") << "Lang - English" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr(">Sounds - Enabled") << ">Sounds - Enabled" << std::endl;

            }
            else {
                std::cout << get_centerr(">Sounds - Disabled") << ">Sounds - Disabled" << std::endl;

            }
            std::cout << get_centerr("Back") << "Back" << std::endl;
            break;
        case 2:
            std::cout << get_centerr("Lang - English") << "Lang - English" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr("Sounds - Enabled") << "Sounds - Enabled" << std::endl;

            }
            else {
                std::cout << get_centerr("Sounds - Disabled") << "Sounds - Disabled" << std::endl;

            }
            std::cout << get_centerr(">Back") << ">Back" << std::endl;
            break;
        }
    }
}

