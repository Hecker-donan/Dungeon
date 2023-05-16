#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "classes.h"



Player::Player(Room room, int x, int y) {
    this->x = x;
    this->y = y;
    this->room = room;
}

Room::Room() {

}

Room::Room(int number, Player player) {
    this->number = number;

}

Screen::Screen(states state) {
    this->state = state;
}

void Screen::changeState(states state) {
    this->state = state;
}

states Screen::getState() {
    return this->state;
}

std::map<std::string, std::string> Russian_loc = {
    {"newgame", "Новая игра"},
    {"settings", "Настройки"},
    {"lang", "Язык"},
    {"sounds", "Звуки"},
    {"back", "Назад"},
    {"lang_name", "Русский"},
    {"on", "Включены"},
    {"off", "Выключены"}

};

std::map<std::string, std::string> English_loc = {
    {"newgame", "New game"},
    {"settings", "Settings"},
    {"lang", "Lang"},
    {"sounds", "Sounds"},
    {"back", "Back"},
    {"lang_name", "English"},
    {"on", "Enabled"},
    {"off", "Disabled"}


};

std::map<std::string, std::string> Sounds = {
    {"choice", "resources/audio/choice.wav"},

};

std::map<Languages, std::map<std::string, std::string>> get_loc = {
    {Russian, Russian_loc},
    {English, English_loc}

};


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

    if (this->sounds) {
        file << "sounds=true" << std::endl;
    }
    else {
        file << "sounds=false" << std::endl;
    }
    
    
    file.close();

}


void print_c(std::string text) {
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
    std::cout << result << text << std::endl;
}


// выводит настройки для главного меню в зависимости от самих настроек
void Settings::print_settings(Settings& settings) {
    std::ios::sync_with_stdio(false);

    auto loc = get_loc[settings.getLang()];


        switch (settings.get_chooseds()) {
        case 0:

            print_c("-> " + loc["lang"] + " - " + loc["lang_name"] + " <-");
            

            (settings.getSounds()) ? print_c(loc["sounds"] + " - " + loc["on"]) : print_c(loc["sounds"] + " - " + loc["off"]);

            print_c(loc["back"]);
            break;
        case 1:
            print_c(loc["lang"] + " - " + loc["lang_name"]);

            (settings.getSounds()) ? print_c("-> " + loc["sounds"] + " - " + loc["on"] + " <-") : print_c("-> " + loc["sounds"] + " - " + loc["off"] + " <-");

            print_c(loc["back"]);
            break;
        case 2:
            print_c(loc["lang"] + " - " + loc["lang_name"]);


            (settings.getSounds()) ? print_c(loc["sounds"] + " - " + loc["on"]) : print_c(loc["sounds"] + " - " + loc["off"]);

            print_c("-> " + loc["back"] + " <-");
            break;

        }


   
}


