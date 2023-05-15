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




// �������� ���� ����
void Settings::changeLang(Languages lang)
{
    this->lang = lang;
}

// ������ ���� ����
Languages Settings::getLang()
{
    return this->lang;
}


// ���������� ����� ����������� ��� ���
void Settings::changeSounds(bool music)
{
    this->sounds = music;
}

// ������, �������� ����� ��� ���
bool Settings::getSounds()
{
    return this->sounds;
}

// ����������, ������� ��������� ��� ���
void Settings::set_opened(bool arg)
{
    this->opened = arg;
}

// ������ ������� ��������� ��� ���
bool Settings::is_opened()
{
    return this->opened;
}

// ���������� ��������� ����� ������ � ����������
void Settings::set_chooseds(int arg)
{
    this->chooseds = arg;
}

// �������� ������� ���������� ����� ������ � ����������
int Settings::get_chooseds()
{
    return this->chooseds;
}


// ���������� ����� �������� ������ ���������� �� this
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
    int width = 80; // ������ ������� �� ���������
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // �������� ������ �������
    }
    int padding = (width - text.length()) / 2; // ��������� ������ �����
    std::string result;
    for (int i = 0; i < padding; i++) {
        result += " "; // ��������� ������ ����� � ���������
    }
    return result;
}

// ������� ��������� ��� �������� ���� � ����������� �� ����� ��������
void Settings::print_settings(Settings& settings) {
    std::ios::sync_with_stdio(false);

    if (settings.getLang() == Russian) {
        switch (settings.get_chooseds()) {
        case 0:
            std::cout << get_centerr(">���� - �������") << ">���� - �������" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr("����� - ��������") << "����� - ��������" << std::endl;

            }
            else {
                std::cout << get_centerr("����� - ���������") << "����� - ���������" << std::endl;

            }

            std::cout << get_centerr("�����") << "�����" << std::endl;
            break;
        case 1:
            std::cout << get_centerr("���� - �������") << "���� - �������" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr(">����� - ��������") << ">����� - ��������" << std::endl;

            }
            else {
                std::cout << get_centerr(">����� - ���������") << ">����� - ���������" << std::endl;

            }

            std::cout << get_centerr("�����") << "�����" << std::endl;
            break;
        case 2:
            std::cout << get_centerr("���� - �������") << "���� - �������" << std::endl;
            if (settings.getSounds() == true) {
                std::cout << get_centerr("����� - ��������") << "����� - ��������" << std::endl;

            }
            else {
                std::cout << get_centerr("����� - ���������") << "����� - ���������" << std::endl;

            }

            std::cout << get_centerr(">�����") << ">�����" << std::endl;
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

