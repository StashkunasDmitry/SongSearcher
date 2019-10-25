#include <iostream>
#include "song.h"
#include "vector"
#include <fstream>
#include <fstream>
#include <string>
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
	while (getline(file, str)) //getline(istream & is, string &s,char c='\n'),читает из потока is, в строку s пока 
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

	if (count == 1)
	{
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

void add(ifstream &file)//функция добавления песни в файл 
{
	/*cout << "Введите номер вашей песни" << endl;
	int num;
	cin >> num;
	//здесь должен быть цикл проверки на число
	string a;
	cin >> a;
	cout << "Add your song" << endl;
	ofstream fout("myBase.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	//fout.open("/myBase.txt"); // связываем объект с файлом
	if (!fout)
	{
		cout << "Ты лох" << endl;
	}
	fout << a; // запись строки в файл
	fout.close(); // закрываем файл*/
}

void deleteSong(ifstream &file)//функция удаления песни из файла
{

	cout << "Delete your song" << endl;

}

void show()//функция вывода аккордов
{
	cout << "Now you'll see all chords" << endl;
	cout << "Choose your tonal chord" << endl;
	cout << "| Number |   Key   |     Chords                   |" << endl;
	cout << "|=================================================|" << endl;
	cout << "|   1.   |  C-Am   | C,F,G,Am,Dm,E,[Em,A]         |" << endl;
	cout << "|   2.   |  C#-A#m | C#,F#,G#,A#m,D#m,F,[Fm,A#]   |" << endl;
	cout << "|   3.   |  D-Bm   | D,G,A,Bm,Em,F#,[F#m,B]       |" << endl;
	cout << "|   4.   |  D#-Cm  | D#,G#,A#,Cm,Fm,G,[Gm,C]      |" << endl;
	cout << "|   5.   |  E-C#m  | E,A,B,C#m,F#m,G#,[G#m,C#]    |" << endl;
	cout << "|   6.   |  F-Dm   | F,A#,C,Dm,Gm,A,[Am,D]        |" << endl;
	cout << "|   7.   |  F#-D#m | F#,B,C#,D#m,G#m,A#,[A#m,D#]  |" << endl;
	cout << "|   8.   |  G-Em   | G,C,D,Em,Am,B,[Bm,E]         |" << endl;
	cout << "|   9.   |  G#-Fm  | G#,C#,D#,Fm,A#m,C,[Cm,F]     |" << endl;
	cout << "|   10.  |  A-F#m  | A,D,F,F#m,Bm,C#,[C#m,F#]     |" << endl;
	cout << "|   11.  |  A#-Gm  | A#,D#,F,Gm,Cm,D,[Dm,G]       |" << endl;
	cout << "|   12.  |  B-E    | B,E,F#,G#m,C#m,D#,[D#m,G#]   |" << endl;
	cout << "|=================================================|" << endl;
	int key;
	cin >> key;
	switch (key)
	{
	case 1:
		cout << "--------C--------" << endl; //ТОНАЛЬНОСТЬ НОМЕР 1
		cout << " 6  5  4  3  2  1  " << endl;//ОСТОРОЖНО ОЧЕНЬ МНОГО КОДА, МОЖНО ЗАПУТАТЬСЯ
		cout << " ================  " << endl;//ТУТ ПРОСТО ВЫВОДЯТСЯ АППЛИКАТУРЫ АККОРДОВ, А ИХ ТУТ МНОГО
		cout << " |  |  |  |  1  |  I" << endl;//И ЗАНИМАЮТ ОНИ МЕСТО
		cout << " |  |  2  |  |  |  II" << endl;//УДАЧИ ПУТНИК
		cout << " |  3  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;  
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------F--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------G--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  2  |  |  |  |  II" << endl;
		cout << " 3  |  |  |  |  3  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Am--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  3  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Dm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  1  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  |  |  |  3  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------E--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  1  |  |  I" << endl;
		cout << " |  2  3  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Em--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  3  2  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------A--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  1  2  3  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////  //////  
		//////  //////  
		//////  //////  
		//////  //////  
		//////  //////  

		break;
	case 2:
		cout << "--------C#--------" << endl;//ТОНАЛЬНОСТЬ НОМЕР 2!!!
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  1  |  II" << endl;
		cout << " |  |  2  |  |  |  III" << endl;
		cout << " |  3  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------F#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  II" << endl;
		cout << " |  |  |  2  |  |  III" << endl;
		cout << " |  3  4  |  |  |  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------G#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  2  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------A#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  1  2  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------D#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  1  |  |  |  I" << endl;
		cout << " |  |  |  |  |  2  II" << endl;
		cout << " |  |  |  3  |  |  III" << endl;
		cout << " |  |  |  |  4  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------F--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Fm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------A#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  1  |  |  |  1  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  2  3  4  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////  //////  //////  
		//////  //////  ////// 
		//////  //////  //////
		//////  //////  //////
		//////  //////  //////
		break;
	case 3:
		cout << "--------D--------" << endl;// ТОНАЛЬНОСТЬ НОМЕР ТРИ!
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  |  1  |  2 II" << endl;
		cout << " |  |  |  |  3  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------G--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  2  |  |  |  |  II" << endl;
		cout << " 3  |  |  |  |  3  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------A--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  1  2  3  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Bm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  2  |  II" << endl;
		cout << " |  |  3  4  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Em--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  3  2  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------F#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  II" << endl;
		cout << " |  |  |  1  |  |  III" << endl;
		cout << " |  3  4  |  |  |  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------F#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------B--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  3  2  1  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///   ///		///
		///   ///	  ///
		///   ///	///
		///   /// ///
		///   ///
		break;
	case 4:
		cout << "--------D#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  1  |  IV" << endl;
		cout << " |  |  2  |  |  |  V" << endl;
		cout << " |  3  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------G#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  2  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------A#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  1  |  |  |  1  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  2  3  4  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Cm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  1  2  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Fm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  1  |  |  |  I" << endl;
		cout << " |  |  |  |  |  2  II" << endl;
		cout << " |  |  |  3  |  |  III" << endl;
		cout << " |  |  |  |  4  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------G--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  1  |  |  |  |  II" << endl;
		cout << " 2  |  |  |  |  3  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Gm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |  3  4  |  |  |  V" << endl;
		cout << " |  |  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------C--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  |  |  |  II" << endl;
		cout << " |  3  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		   ///		///
		   ///	  ///	
		  ///	///
		  //////
		  ///
		break;
	case 5:
		cout << "--------E--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  1  |  |  I" << endl;
		cout << " |  2  3  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------A--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  1  2  3  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------B--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  3  2  1  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------C#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  1  |  V" << endl;
		cout << " |  |  3  2  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------F#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------G#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  2  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------G#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------C#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  1  |  II" << endl;
		cout << " |  |  2  |  |  |  III" << endl;
		cout << " |  3  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///		   ////  ////
		 ////    ///     ////
		  //// ///       ////
		    ////         ////
		break;
	case 6:
		cout << "--------F--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------A#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  1  |  |  |  1  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  2  3  4  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------C--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  |  |  |  II" << endl;
		cout << " |  3  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Dm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  1  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  |  |  |  3  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Gm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |  3  4  |  |  |  V" << endl;
		cout << " |  |  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------A--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  1  2  3  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Am--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  3  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------D--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  |  1  |  2 II" << endl;
		cout << " |  |  |  |  3  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////		  ////  ////   ////
		  ////		////	////   ////	
		    ////  ////  	////   ////
		       ////			////   ////
		break;
	case 7:
		cout << "--------F#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------B--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  3  2  1  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------C#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  1  |  II" << endl;
		cout << " |  |  2  |  |  |  III" << endl;
		cout << " |  3  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------D#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  1  |  |  |  I" << endl;
		cout << " |  |  |  |  |  2  II" << endl;
		cout << " |  |  |  3  |  |  III" << endl;
		cout << " |  |  |  |  4  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------G#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------A#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  1  |  |  |  1  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  2  3  4  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------A#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  1  2  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------D#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  1  |  IV" << endl;
		cout << " |  |  2  |  |  |  V" << endl;
		cout << " |  3  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		  ///////
		////   ///
		 ////////
		////   ///
		 ///////
		break;
	case 8:
		cout << "--------G--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  1  |  |  |  |  II" << endl;
		cout << " 2  |  |  |  |  3  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------C--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  |  |  |  II" << endl;
		cout << " |  3  |  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------D--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  |  1  |  2  II" << endl;
		cout << " |  |  |  |  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Em--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  2  3  |  |  | II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Am--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  3  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------B--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  3  2  1  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Bm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  2  |  II" << endl;
		cout << " |  |  3  4  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------E--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  1  |  |  I" << endl;
		cout << " |  2  3  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;

		/////////
		///   ///
		///	  ///	
		/////////
			  ///
		////////
		break;
	case 9:
		cout << "--------G#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  2  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------C#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  1  |  II" << endl;
		cout << " |  |  2  |  |  |  III" << endl;
		cout << " |  3  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------D#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  1  |  IV" << endl;
		cout << " |  |  2  |  |  |  V" << endl;
		cout << " |  3  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Fm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  1  |  |  |  I" << endl;
		cout << " |  |  |  |  |  2  II" << endl;
		cout << " |  |  |  3  |  |  III" << endl;
		cout << " |  |  |  |  4  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------A#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  1  2  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------C--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  I" << endl;
		cout << " |  |  2  |  |  |  II" << endl;
		cout << " |  3  |  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Cm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  1  2  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------F--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///   /////////
		///   ///   ///
		///   ///   ///
		///   /////////
		break;
	case 10:
		cout << "--------A--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  1  2  3  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------D--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  |  1  |  2  II" << endl;
		cout << " |  |  |  |  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------E--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  1  |  |  I" << endl;
		cout << " |  2  3  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------F#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |  2  3  |  |  |  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Bm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  II" << endl;
		cout << " |  |  |  |  2  |  III" << endl;
		cout << " |  |  3  4  |  |  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------C#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  1  |  II" << endl;
		cout << " |  |  2  |  |  |  III" << endl;
		cout << " |  3  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------C#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  2  |  V" << endl;
		cout << " |  |  3  4  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------F#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  II" << endl;
		cout << " |  |  |  2  |  |  III" << endl;
		cout << " |  3  4  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		   //////////   ////////////
			///////      ///////
			///////      ///////
			///////      ///////
			///////      ///////
			///////      ///////
		break;
	case 11:
		cout << "--------A#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  1  |  |  |  1  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  2  3  4  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------D#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  1  |  IV" << endl;
		cout << " |  |  2  |  |  |  V" << endl;
		cout << " |  3  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------F--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  2  |  |  II" << endl;
		cout << " |  3  4  |  |  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------Gm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------Cm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  1  2  3  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------D--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  |  |  1  |  3  II" << endl;
		cout << " |  |  |  |  2  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------Dm--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  1  |  |  |  I" << endl;
		cout << " |  |  |  |  |  2  II" << endl;
		cout << " |  |  |  3  |  |  III" << endl;
		cout << " |  |  |  |  4  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------G--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  |  |  |  I" << endl;
		cout << " |  1  |  |  |  |  II" << endl;
		cout << " 2  |  |  |  |  3  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////          ///////////
		/////	              ///
		/////	     ///////////
		/////       ///       
		/////      //////////
		break;
	case 12:
		cout << "--------B--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  |  II" << endl;
		cout << " |  |  2  3  4  |  III" << endl;
		cout << " |  |  |  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------E--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " |  |  |  1  |  |  I" << endl;
		cout << " |  2  3  |  |  |  II" << endl;
		cout << " |  |  |  |  |  |  III" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------F#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  II" << endl;
		cout << " |  |  |  2  |  |  III" << endl;
		cout << " |  3  4  |  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		///////////////////////////////////////////
		cout << "--------G#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		cout << "--------C#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  |  2  |  V" << endl;
		cout << " |  |  3  4  |  |  VI" << endl;
		cout << " |  |  |  |  |  |  VII" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		////////////////////////////////////////
		cout << "--------D#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  III" << endl;
		cout << " |  |  |  |  1  |  IV" << endl;
		cout << " |  |  2  |  |  |  V" << endl;
		cout << " |  3  |  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////
		cout << "--------D#m--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  I" << endl;
		cout << " |  |  |  |  |  2  II" << endl;
		cout << " |  |  3  |  |  |  III" << endl;
		cout << " |  |  |  4  |  |  IV" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		//////////////////////////////////////////
		cout << "--------G#--------" << endl;
		cout << " 6  5  4  3  2  1  " << endl;
		cout << " ================  " << endl;
		cout << " ################  IV" << endl;
		cout << " |  |  |  2  |  |  V" << endl;
		cout << " |  3  4  |  |  |  VI" << endl;
		cout << " |==============|" << endl;
		cout << endl;
		cout << endl;
		/////////////////////////////////////////
		break;

	default:
		break;
	}
}

//Ооооочень длинющая функция, которая показывает аппликатуры 

void transpose()
{
	//функция транспонирования
	cout << "| Number |   Key   |     Chords                   |" << endl;
	cout << "|=================================================|" << endl;
	cout << "|   1.   |  C-Am   | C,F,G,Am,Dm,E,[Em,A]         |" << endl;
	cout << "|   2.   |  C#-A#m | C#,F#,G#,A#m,D#m,F,[Fm,A#]   |" << endl;
	cout << "|   3.   |  D-Bm   | D,G,A,Bm,Em,F#,[F#m,B]       |" << endl;
	cout << "|   4.   |  D#-Cm  | D#,G#,A#,Cm,Fm,G,[Gm,C]      |" << endl;
	cout << "|   5.   |  E-C#m  | E,A,B,C#m,F#m,G#,[G#m,C#]    |" << endl;
	cout << "|   6.   |  F-Dm   | F,A#,C,Dm,Gm,A,[Am,D]        |" << endl;
	cout << "|   7.   |  F#-D#m | F#,B,C#,D#m,G#m,A#,[A#m,D#]  |" << endl;
	cout << "|   8.   |  G-Em   | G,C,D,Em,Am,B,[Bm,E]         |" << endl;
	cout << "|   9.   |  G#-Fm  | G#,C#,D#,Fm,A#m,C,[Cm,F]     |" << endl;
	cout << "|   10.  |  A-F#m  | A,D,F,F#m,Bm,C#,[C#m,F#]     |" << endl;
	cout << "|   11.  |  A#-Gm  | A#,D#,F,Gm,Cm,D,[Dm,G]       |" << endl;
	cout << "|   12.  |  B-E    | B,E,F#,G#m,C#m,D#,[D#m,G#]   |" << endl;
	cout << "|=================================================|" << endl;
	cout << "Choose the number what chords do you want to transpose" << endl;
	int a = 2;
	int num;
	cin >> num;
	if (num < 1 || num > 12)
	{
		cout << "Enter correct number : 1,2,3,4,5,6,7,8,9,10,11,12." << endl;
	}
	else
	{
	
					cout << "Choose the key" << endl;
					cout << "=============================================================" << endl;
					cout << "| +1 = 1  | +2 = 2  | +3 = 3  | +4 = 4  | +5 = 5  | +6 = 6  |" << endl;
					cout << "| -1 = 11 | -2 = 12 | -3 = 13 | -4 = 14 | -5 = 15 | -6 = 16 |" << endl;
					cout << "=============================================================" << endl;
					unsigned int key;
					cin >> key;
					if ((key < 1 || key > 16) && (key < 7 || key > 10))
					{
						cout << "Enter correct number : 1,2,3,4,5,6,11,12,13,14,15,16." << endl;
					}
					else
							{
							//транспонирование
							switch (num)
	{
	case 1:
		switch (key)
		{
		case 1:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|  C#-A#m   | C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 2:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|   D-Bm    | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 3:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|   D#-Cm   | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 4:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|   E-C#m   | E,A,B,C#m,F#m,G#,[G#m,C#] |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 5:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|   F-Dm    | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 6:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|  F#-D#m   |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 11:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|    B-E    | B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 12:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|   A#-Gm   | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 13:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|  A-F#m    | A,D,F,F#m,Bm,C#,[C#m,F#]  |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 14:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|  G#-Fm    | G#,C#,D#,Fm,A#m,C,[Cm,F]  |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 15:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|    G-Em   | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "==============================================================================" << endl;
			break;
		case 16:
			cout << "==============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords    | Final Key |      Final Chords         |" << endl;
			cout << "|==============|=====================|===========|===========================|" << endl;
			cout << "|    C-Am      | C,F,G,Am,Dm,E,[Em,A]|   F#-D#m  |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "==============================================================================" << endl;
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (key)
		{
		case 1:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  D-Bm     | D,G,A,Bm,Em,F#,[F#m,B]|" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 2:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  D#-Cm    |D#,G#,A#,Cm,Fm,G,[Gm,C]|" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 3:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  E-C#m    |E,A,B,C#m,F#m,G#,[G#m,C#]|" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 4:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|    F-Dm   | F,A#,C,Dm,Gm,A,[Am,D]   |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 5:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  F#-D#m   |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 6:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|   G-Em    | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 11:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|   C-Am    | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 12:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  B-E      |B,E,F#,G#m,C#m,D#,[D#m,G#] |" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 13:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]| A#-Gm     | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 14:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]| A-F#m     | A,D,F,F#m,Bm,C#,[C#m,F#]  |" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 15:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  G#-Fm    | G#,C#,D#,Fm,A#m,C,[Cm,F]  |" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 16:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|  G-Em     | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "===================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
	
	case 3:
		switch (key)
		{
		case 1:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  D#-Cm    |D#,G#,A#,Cm,Fm,G,[Gm,C]|" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 2:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  E-C#m    |E,A,B,C#m,F#m,G#,[G#m,C#]|" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 3:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  F-Dm     | F,A#,C,Dm,Gm,A,[Am,D] |" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 4:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  F#-D#m   |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 5:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  G-Em     | G,C,D,Em,Am,B,[Bm,E]  |" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 6:
			cout << "================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords      |" << endl;
			cout << "|==============|==========================|===========|========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  G#-Fm    |G#,C#,D#,Fm,A#m,C,[Cm,F]|" << endl;
			cout << "================================================================================" << endl;
			break;
		case 11:
			cout << "==================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords        |" << endl;
			cout << "|==============|==========================|===========|==========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  C#-A#m   |C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 12:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  C-Am     | C,F,G,Am,Dm,E,[Em,A]  |" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 13:
			cout << "==================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords        |" << endl;
			cout << "|==============|==========================|===========|==========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  B-E      |B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 14:
			cout << "===============================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords     |" << endl;
			cout << "|==============|==========================|===========|====================== |" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  A#-Gm    | A#,D#,F,Gm,Cm,D,[Dm,G]|" << endl;
			cout << "===============================================================================" << endl;
			break;
		case 15:
			cout << "================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords      |" << endl;
			cout << "|==============|==========================|===========|========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  A-F#m    |A,D,F,F#m,Bm,C#,[C#m,F#]|" << endl;
			cout << "================================================================================" << endl;
			break;
		case 16:
			cout << "================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords      |" << endl;
			cout << "|==============|==========================|===========|========================|" << endl;
			cout << "|   D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]   |  G#-Fm    |G#,C#,D#,Fm,A#m,C,[Cm,F]|" << endl;
			cout << "================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 4:
		switch (key)
		{
			
		case 1:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  E-C#m    |E,A,B,C#m,F#m,G#,[G#m,C#]|" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 2:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  F-Dm     |F,A#,C,Dm,Gm,A,[Am,D]    |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 3:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  | F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 4:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  G-Em     | G,C,D,Em,Am,B,[Bm,E]    |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 5:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  | G#-Fm     | G#,C#,D#,Fm,A#m,C,[Cm,F]|" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 6:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  A-F#m    | A,D,F,F#m,Bm,C#,[C#m,F#]|" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 11:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |   D-Bm   | D,G,A,Bm,Em,F#,[F#m,B]   |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 12:
			cout << "==================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords        |" << endl;
			cout << "|==============|==========================|===========|==========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  | C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 13:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  C-Am     | C,F,G,Am,Dm,E,[Em,A]    |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 14:
			cout << "==================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords        |" << endl;
			cout << "|==============|==========================|===========|==========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  B-E      |B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 15:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  A#-Gm    |A#,D#,F,Gm,Cm,D,[Dm,G]   |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 16:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]  |  A-F#m    | A,D,F,F#m,Bm,C#,[C#m,F#]|" << endl;
			cout << "=================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 5:
		switch (key)
		{
		case 1:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]   |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 2:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "===================================================================================" << endl;
			break;
		case 3:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| G-Em      | G,C,D,Em,Am,B,[Bm,E]    |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 4:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| G#-Fm  | G#,C#,D#,Fm,A#m,C,[Cm,F]   |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 5:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| A-F#m     |A,D,F,F#m,Bm,C#,[C#m,F#] |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 6:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| A#-Gm     | A#,D#,F,Gm,Cm,D,[Dm,G]  |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 11:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C] |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 12:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]  |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 13:
			cout << "==================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords        |" << endl;
			cout << "|==============|==========================|===========|==========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 14:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| C-Am      | C,F,G,Am,Dm,E,[Em,A]    |" << endl;
			cout << "=================================================================================" << endl;
			break;
		case 15:
			cout << "==================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords        |" << endl;
			cout << "|==============|==========================|===========|==========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| B-E       |B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 16:
			cout << "=================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords       |" << endl;
			cout << "|==============|==========================|===========|=========================|" << endl;
			cout << "|    E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#]| A#-Gm     |A#,D#,F,Gm,Cm,D,[Dm,G]   |" << endl;
			cout << "=================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 6:
		switch (key)
		{
		case 1:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 2:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | G-Em      |G,C,D,Em,Am,B,[Bm,E]       |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 3:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | G#-Fm     |G#,C#,D#,Fm,A#m,C,[Cm,F]   |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 4:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | A-F#m     |A,D,F,F#m,Bm,C#,[C#m,F#]   |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 5:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | A#-Gm     | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 6:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | B-E       | B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 11:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | E-C#m     |E,A,B,C#m,F#m,G#,[G#m,C#]  |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 12:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | D#-Cm     |D#,G#,A#,Cm,Fm,G,[Gm,C]    |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 13:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 14:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#] |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 15:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    |C-Am       |C,F,G,Am,Dm,E,[Em,A]       |" << endl;
			cout << "==================================================================================" << endl;
			break;
		case 16:
			cout << "===================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords         | Final Key |      Final Chords         |" << endl;
			cout << "|==============|==========================|===========|===========================|" << endl;
			cout << "|    F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]    | B-E       | B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "==================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 7:
		switch (key)
		{
		case 1:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| G-Em      | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 2:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| G#-Fm     |G#,C#,D#,Fm,A#m,C,[Cm,F]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| A-F#m     |A,D,F,F#m,Bm,C#,[C#m,F#]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 4:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| A#-Gm     | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 5:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| B-E       | B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 6:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| C-Am      | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 11:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|  F-Dm     | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 12:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 13:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 14:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 15:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| C#-A#m    | C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 16:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|    F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]| C-Am      | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 8:
		switch (key)
		{
		case 1:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | G#-Fm     | G#,C#,D#,Fm,A#m,C,[Cm,F]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 2:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | A-F#m     | A,D,F,F#m,Bm,C#,[C#m,F#]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | A#-Gm     | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 4:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      |    B-E    |B,E,F#,G#m,C#m,D#,[D#m,G#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 5:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | C-Am      | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 6:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 11:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 12:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 13:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | E-C#m     |E,A,B,C#m,F#m,G#,[G#m,C#]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 14:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      |D#-Cm      | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 15:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 16:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   G-Em       | G,C,D,Em,Am,B,[Bm,E]      | C#-A#m    | C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 9:
		switch (key)
		{
		case 1:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | A-F#m     |A,D,F,F#m,Bm,C#,[C#m,F#]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 2:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  |A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | B-E       |B,E,F#,G#m,C#m,D#,[D#m,G#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 4:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  |C-Am       | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 5:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | C#-A#m    |C#,F#,G#,A#m,D#m,F,[Fm,A#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 6:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  |D-Bm       | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 11:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | G-Em      | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 12:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 13:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  |F-Dm       | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 14:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | E-C#m     |E,A,B,C#m,F#m,G#,[G#m,C#]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 15:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  |D#-Cm      | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 16:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|  G#-Fm       | G#,C#,D#,Fm,A#m,C,[Cm,F]  | D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 10:
		switch (key)
		{
		case 1:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 2:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |    B-E    |B,E,F#,G#m,C#m,D#,[D#m,G#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |C-Am       | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 4:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |C#-A#m     |C#,F#,G#,A#m,D#m,F,[Fm,A#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 5:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  | D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 6:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |D#-Cm      | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 11:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |G#-Fm      | G#,C#,D#,Fm,A#m,C,[Cm,F]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 12:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  | G-Em      | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 13:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  | F#-D#m    |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 14:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |F-Dm       | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 15:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |E-C#m      | E,A,B,C#m,F#m,G#,[G#m,C#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 16:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A-F#m      | A,D,F,F#m,Bm,C#,[C#m,F#]  |D#-Cm      | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 11:
		switch (key)
		{
		case 1:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    B-E    | B,E,F#,G#m,C#m,D#,[D#m,G#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 2:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    C-Am   | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    C#-A#m | C#,F#,G#,A#m,D#m,F,[Fm,A#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 4:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    D-Bm   | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 5:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |   D#-Cm   | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 6:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    E-C#m  | E,A,B,C#m,F#m,G#,[G#m,C#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 11:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    A-F#m  | A,D,F,F#m,Bm,C#,[C#m,F#]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 12:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |   G#-Fm   | G#,C#,D#,Fm,A#m,C,[Cm,F]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 13:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |   G-Em    | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 14:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |    F#-D#m |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 15:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |   F-Dm    | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 16:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   A#-Gm      | A#,D#,F,Gm,Cm,D,[Dm,G]    |   E-C#m   | E,A,B,C#m,F#m,G#,[G#m,C#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	case 12:
		switch (key)
		{
		case 1:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] |  C-Am     | C,F,G,Am,Dm,E,[Em,A]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 2:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] |  C#-A#m   |C#,F#,G#,A#m,D#m,F,[Fm,A#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | D-Bm      | D,G,A,Bm,Em,F#,[F#m,B]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 4:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | D#-Cm     | D#,G#,A#,Cm,Fm,G,[Gm,C]   |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 5:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | E-C#m     | E,A,B,C#m,F#m,G#,[G#m,C#] |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 6:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | F-Dm      | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 11:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] |  A#-Gm    | A#,D#,F,Gm,Cm,D,[Dm,G]    |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 12:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | A-F#m     | A,D,F,F#m,Bm,C#,[C#m,F#]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 13:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | G#-Fm     | G#,C#,D#,Fm,A#m,C,[Cm,F]  |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 14:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] | G-Em      | G,C,D,Em,Am,B,[Bm,E]      |" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 15:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] |  F#-D#m   |F#,B,C#,D#m,G#m,A#,[A#m,D#]|" << endl;
			cout << "====================================================================================" << endl;
			break;
		case 16:
			cout << "====================================================================================" << endl;
			cout << "|  Start Key   |     Start Chords          | Final Key |      Final Chords         |" << endl;
			cout << "|==============|===========================|===========|===========================|" << endl;
			cout << "|   B-E        |B,E,F#,G#m,C#m,D#,[D#m,G#] |  F-Dm     | F,A#,C,Dm,Gm,A,[Am,D]     |" << endl;
			cout << "====================================================================================" << endl;
			break;
		default:
			break;
		}
		break;
		
	default:
		break;
	}//транспонирование
							}
	}


}



void clearscreen()//очистить экран
{
	system("cls");
}


