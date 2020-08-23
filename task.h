#pragma once
#include "object.h"

class Task
{
protected:
	ObjectData &T;
	int i, j, id;
	bool flag, found, *color;
public:
	Task(ObjectData &arg) :T(arg){}
	void print_1();
	void print_2();
	virtual void init();
	virtual int step();
};
