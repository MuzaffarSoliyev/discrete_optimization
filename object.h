#pragma once
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
struct Pair
{
	int a, b;
};

struct ObjectData
{
	Pair *X;
	Pair *Y;
	Pair *result;
	int N, M, P;
	ObjectData(istream& inputStream)
	{
		inputStream >> N >> M;
		P = 0;
		X = new Pair[N];
		Y = new Pair[M];
		result = new Pair[N];
		
		for (int i = 0; i < N; i++)
		{
			inputStream >> X[i].a;
			X[i].b = i;
		}

		for (int j = 0; j < M; j++)
		{
			inputStream >> Y[j].a;
			Y[j].b = j;
		}
		
		ofstream on("intest.txt", ios_base::app);
		on << N << " " << M << endl;
		for (int i = 0; i < N; i++){
			on << X[i].a << " ";
		}
		on << endl;
		for (int i = 0; i < M; i++){
			on << Y[i].a << " ";
		}
		on << endl;
	}
	
};