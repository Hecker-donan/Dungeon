#pragma once
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <map>

extern std::map<std::string, std::string> Russian_loc;
extern std::map<std::string, std::string> English_loc;
extern std::map<std::string, std::string> Sounds;


enum Keys {
	Enter = 13,
	ArrowUp = 72,
	ArrowDown = 80,
	ArrowLeft = 75,
	ArrowRight = 77
};

enum Languages {
	English,
	Russian
};

enum states {
	walk,
	cutscene,
	menu,
	fight
};

extern std::map<Languages, std::map<std::string, std::string>> get_loc;

// ������ � ���������� ������
class Screen {
private:
	states state;
public:
	Screen(states state);


	void changeState(states state);
	states getState();
};


// ������ � �����������
class Settings {
private:
	Languages lang = English;
	bool sounds = true;
	bool opened = false;
	int chooseds = 0;

	Languages read_lang(std::ifstream& file) {
		std::string line;
		while (getline(file, line)) { // ������ ���� ���������
			std::string key, value;
			int pos = line.find('='); // ���� ������� �����������
			if (pos != std::string::npos) { // ���� ����������� ������
				key = line.substr(0, pos); // ��������� ����
				value = line.substr(pos + 1); // ��������� ��������
				// ������������ ���� � ��������
				if (key == "lang") {
					if (value == "eng") {
						return English;
					}
					else {
						return Russian;
					}

				}
			}
		}
	}

	bool read_sounds(std::ifstream& file) {
		std::string line;
		while (getline(file, line)) { // ������ ���� ���������
			std::string key, value;
			int pos = line.find('='); // ���� ������� �����������
			if (pos != std::string::npos) { // ���� ����������� ������
				key = line.substr(0, pos); // ��������� ����
				value = line.substr(pos + 1); // ��������� ��������
				// ������������ ���� � ��������
				if (key == "sounds") {
					if (value == "true") {
						return true;
					}
					else {
						return false;
					}

				}
			}
		}
	}
public:
	Settings() {
		std::string files = "settings.cfg";
		std::ifstream file(files);

		if (file.is_open()) {
			this->lang = read_lang(file);
			this->sounds = read_sounds(file);
			file.close();
		}
		else {
			file.close();
			if (std::filesystem::exists(files)) {
				remove("settings.cfg");
				std::ofstream file(files);
				file << "lang=eng" << std::endl;
				file << "sounds=true" << std::endl;
				file.close();

			}
			else {
				std::ofstream file(files);
				file << "lang=eng" << std::endl;
				file << "sounds=true" << std::endl;
				this->lang = English;
				this->sounds = true;
				file.close();
			}
		}

	};
	// �������� ���� ����
	void changeLang(Languages lang);

	// ������ ���� ����
	Languages getLang();


	// ���������� ����� ����������� ��� ���
	void changeSounds(bool music);

	// ������, �������� ����� ��� ���
	bool getSounds();



	// ������ ������� ��������� ��� ���
	bool is_opened();

	// ����������, ������� ��������� ��� ���
	void set_opened(bool arg);


	// �������� ������� ���������� ����� ������ � ����������
	void set_chooseds(int arg);

	// ���������� ��������� ����� ������ � ����������
	int get_chooseds();


	// ���������� ����� �������� ������ ���������� �� this
	void updateSettings();


	// ������� ��������� ��� �������� ���� � ����������� �� ����� ��������
	void print_settings(Settings& settings);
	
	
};


class Player;
//�������
class Room {
private:
	// ���������� ����� �������
	int number;

	// ������ ������ �������
	int height = 60;
	int weight = 60;

	// ����� � ������ �� ������
	bool UpDoor, LeftDoor, RightDoor, DownDoor;



public:
	Room();
	Room(int number, Player player);

};

//�����
class Player {
private:
	bool started = false;
	int hp = 100;
	Room room;
	int x, y;

public:
	Player(Room room, int x, int y);

	bool getStarted();
	bool setStarted();


	int getHP();


	int getX();
	int getY();

	void setX();
	void setY();


	void moveUp();
	void moveRight();
	void moveLeft();
	void moveDown();


	Room getRoom();
};


// ������ � �����
class Game {
private:
	bool started = false;
	Player player;

public:
	Game();


	Player getPlayer();
};