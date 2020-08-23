#pragma once
#include "object.h"
#include "Generator.h"
#include "task.h"
#include "TASK_OPTIMIZ.h"
#include <ctime>
#include <iostream>
#include <fstream>

class Test
{
	clock_t begin, end;
	double time_1, time_2;
	ofstream f;
	
public:
	Test() { f.open("out.txt"); f.clear(); }
	~Test() { f.close(); }
	void start();
};