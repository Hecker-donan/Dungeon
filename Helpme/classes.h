#pragma once
#include <filesystem>
#include <fstream>
#include <cstdio>


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


