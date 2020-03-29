#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

class search_device
{
 public:

	void files_search(string directory_path, string object) //функция по перебору текстовых файлов в директории logs
	{
		for (auto& pointer : fs::directory_iterator("logs")) //перебор текстовых файлов
		{
			auto p = pointer.path().filename().string(); 

			logs_search(pointer.path().string(), object, p); //чтение файла и поиск навзвания устройства
		}

	}
	void func(string& device2, int& number) //функция с циклом который считывает сколько символов до знака :
	{
		while (device2[number] != ':') //цикл считывает сколько символов до знака :
		number++;
	}

	void logs_search(string path, const string& object, string name) //функция с поиском названия устройства
	{
		fstream log; 

		log.open(path, ios_base::in); //открытие файла log

		while (!log.eof()) //цикл выдаёт истину, если файл пуст, а если файл не пуст, то выдаётся ложь и цикл работает
		{
			string time, name_device, value; //время, название устройства, значение

			getline(log, value); //чтение строки

			if (value.find("garbage") != -1 or value.length() == 0) //проверка на слово garbage и на пустую строку 

			continue; //если условие работает, то идет пропуск оставшейся части кода 

			time = value.substr(0, 1); //убрать время замеров

			value.replace(0, 2, ""); //удаляется 2 символа(убрать время замеров) с начала и на их место вставляется ""(пусто)

			int counter = 0; //переменная равная количеству символов до знака :

			func(value, counter); //функция считывающая сколько символов до знака :

			name_device = value.substr(0, counter); //присваивание названия устройства

			if (name_device != object) //проверка на совпадение с введеным устройством

			continue; //если не совпадает, то идет пропуск оставшейся части кода 

			value.replace(0, counter + 1, "");

			cout << name << "  time - " << time << "  value  - " << value << endl;

		} // вывод названия(год месяц день час) файла без log(), секунды и значение устройства

		log.close();
	}

};

	int main()
	{
		string device1, device2;

		search_device device;

        cout << "logs:\n";

		for (auto& p : fs::directory_iterator("logs")) //вывод названий всех файлов
		{
			string filename = p.path().generic_string(); //присваивание названия файла переменной filename

			cout << filename << '\n';
		}
		cout << "show device\n"; 

		cin >> device1; //ввод названия устройства

		device.files_search("C:/Users/Юлия/source/repos/ConsoleApplication5/ConsoleApplication5/logs", device1);

		return 0;
	}