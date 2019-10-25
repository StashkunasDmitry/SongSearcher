#pragma once
#include <clocale>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <ostream>
#include "menu.h"
void search(ifstream &file);
void add(ifstream &file);
void deleteSong(ifstream &file);
void show();
void transpose();
void clearscreen();

//объявляем функции для song.cpp
