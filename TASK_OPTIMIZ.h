#pragma once
#include "task.h"

class Task_opt : public Task
{
private:
	int algostate;
	bool exit;

	void pswap(Pair &A, Pair &B);

	int Step_Sort_X();
	int Step_Sort_Y();
	int Step_Distribution();
	int Step_Sort_index();
public:
	Task_opt(ObjectData &arg) :Task(arg){}


	void init();
	int step();
};