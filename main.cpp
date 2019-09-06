#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include "menu.h"


using namespace std; // используем стандартное пространство имен

int main() {
	string s; // сюда будем класть считанные строки
	ifstream file("songs.txt", ifstream::binary); // файл из которого читаем (для линукс путь будет выглядеть по другому)
	while (menu(file))
	{
		file.close();
		file.open("songs.txt", ifstream::binary);
	}

	file.close(); // обязательно закрываем файл что бы не повредить его

	return 0;
}
