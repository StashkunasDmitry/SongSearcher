#include <iostream>
#include "song.h"
#include "vector"

using namespace std;

void search(ifstream &file)//функция поиска пенси
{
	cout << "Find your song" << endl;
	string str;         //переменная стринг для строки    
	string findText;    //переменная поиска
	cin >> findText;
	int count = 1;   //счетчик для нумерации песни
	int line = 1;
	vector <int> paticipants; //вектор содержащий искомые песни
	while (getline(file, str) ) //getline(istream & is, string &s,char c='\n'),читает из потока is, в строку s пока 
	{                        //не встретит символ c (без этого символа до новой строки)

		size_t pos = str.find(findText/*мы инициализируем строку которую нужно найти*/);
		if (pos != string::npos)//условие совпадения 
		{
			// paticipants[count] = line;
			paticipants.push_back(line);//вытаскиваем искомые результаты из базы данных
			cout << count/*присваиваем номер искомому результату*/ << ". " << str << endl;//выводим результат
			++count;
			
		}
		++line;
	}
	if (count == 1) {
		cout << "No result" << endl;//в случае, если мы не находим результат, выводим соответствующее сообщение
		return;
	}
	cout << "Input number of song" << endl;
	int numPart;
	cin >> numPart; //вводим номер, предлагаемый поиском
	if (numPart <= paticipants.size())
	{
		ifstream textSong("dataBase\\" + to_string(paticipants[numPart - 1]) + ".txt");//ищем текст песни в файле с текстами
		while (getline(textSong, str))
		{
			cout << str << endl;//выводим текст соответствующей песни
		}
	}
	else
	{
		cout << "ERROR!!!!!!!!!!!" << endl;//если не получилось, выводим соответствующее сообщение
	}
	

}

void add(ifstream &file)
{
	cout << "Add your song" << endl;
}

void deleteSong(ifstream &file)
{
	cout << "Delete your song" << endl;
}

void show()
{
	cout << "In this version doesn't work" << endl;
}


