#pragma once
#include "object.h"

#define constant 2000

class Generator
{

public:
	static void begin(int level)
	{
		srand(time(NULL));
		ofstream f("in.txt");
		f.clear();

			int m = 1 + rand() % constant * level;
			int n = 1 + rand() % m;
		//int m = constant * level;
		//int n = constant * level;

		f << n << " " << m << endl;
		int first_value = 1, last_value = 1000 - 1;
		for (int i = 0; i < n; i++)
			f << first_value + rand() % last_value << " ";
		f << endl;
		for (int j = 0; j < m; j++)
			f << first_value + rand() % last_value << " ";
	}



};

