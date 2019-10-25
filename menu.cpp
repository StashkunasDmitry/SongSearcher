#include <iostream>
#include <Windows.h>
#include "song.h"
#include "menu.h"
using namespace std;



int menu(ifstream &file)
{
	int a = -1;
	cout << "Select" << endl << "1. Search song" << endl << "2. Add song\n3. Remove song\n4. Show chords\n5.transpose\n6. Clear screen\n0.Exit" << endl;
	cin >> a;
	try //нельзя допустить ввод других символов, кроме указанных
	{
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int error)
	{
		cout << "Type number of menu" << endl;
		cin.clear();
		return true;
	}
	switch (a)
	{
	case 1:
		search(file);//функция поиска песни
		break;
	case 2:
		add(file);//функция добавления песни
		break;
	case 3:
		deleteSong(file);//функция удаления песни
		break;
	case 4:
		show();//функция показа аккордов
		break;
	case 5:
		transpose();
		break;
	case 6:
		clearscreen();
		break;
	case 0:
		return false;

	default:
		break;
	}


	//system("pause");
	return true;
}
