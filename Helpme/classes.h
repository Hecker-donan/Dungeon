#pragma once
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <map>

extern std::map<std::string, std::string> Russian_loc;
extern std::map<std::string, std::string> English_loc;

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

// работа с состоянием экрана
class Screen {
private:
	states state;
public:
	Screen(states state);
	void changeState(states state);
	states getState();
};


// работа с настройками
class Settings {
private:
	Languages lang = English;
	bool sounds = true;
	bool opened = false;
	int chooseds = 0;

	Languages read_lang(std::ifstream& file) {
		std::string line;
		while (getline(file, line)) { // читаем файл построчно
			std::string key, value;
			int pos = line.find('='); // ищем позицию разделителя
			if (pos != std::string::npos) { // если разделитель найден
				key = line.substr(0, pos); // извлекаем ключ
				value = line.substr(pos + 1); // извлекаем значение
				// обрабатываем ключ и значение
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
		while (getline(file, line)) { // читаем файл построчно
			std::string key, value;
			int pos = line.find('='); // ищем позицию разделителя
			if (pos != std::string::npos) { // если разделитель найден
				key = line.substr(0, pos); // извлекаем ключ
				value = line.substr(pos + 1); // извлекаем значение
				// обрабатываем ключ и значение
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
	// изменить язык игры
	void changeLang(Languages lang);

	// узнать язык игры
	Languages getLang();


	// установить звуки включенными или нет
	void changeSounds(bool music);

	// узнать, включены звуки или нет
	bool getSounds();



	// узнать открыты настройки или нет
	bool is_opened();

	// установить, открыты настройки или нет
	void set_opened(bool arg);


	// изменяет текущий порядковый номер выбора в настройках
	void set_chooseds(int arg);

	// возвращает порядкоый номер выбора в настройках
	int get_chooseds();


	// обновление файла настроек новыми значениями из this
	void updateSettings();


	// выводит настройки для главного меню в зависимости от самих настроек
	void print_settings(Settings& settings);
	
	
};


