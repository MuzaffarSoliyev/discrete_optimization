#include "task.h"
void Task::init()
{
	i = 0; j = 0;
	flag = false; found = false; id = -1;
	color = new bool[T.M];
	for (int c = 0; c < T.M; c++)
		color[c] = false;

}

int Task::step()
{
	if (i >= T.N)
	{
		return 0;
	}

	if (j >= T.M)
	{	
		if (found)
		{
			found = false;
			T.X[i].a = T.Y[id].b + 1;
			color[id] = true;
			T.P++;
			id = -1;
		}
		else
		{
			T.X[i].a = 0;
		}
		j = 0; i++;

	}
	else
	{
		if (T.X[i].a < T.Y[j].a && !color[j])
		{
			if (id == -1)
			{
				id = j;
				found = true;
			}
			if (T.Y[id].a > T.Y[j].a)
			{
				id = j;
				found = true;
			}
		}
		j++;
	}
	return 1;

	/*
	for (int i = 0; i < T.N; i++)
	{
		flag = false;
		for (int j = 0; j < T.M; j++)
		{
			if (T.X[i].a < T.Y[j].a && !color[j])
			{
				T.X[i].a = T.Y[j].b + 1;
				//array_[i].flag = true;
				color[j] = true;
				flag = true;
				T.P++;
				break;
			}

		}
		if (!flag)
		{
			T.X[i].a = 0;
		}
	}
	*/
}

void Task::print_1()
{
	ofstream f("out1.txt", ios_base ::app);

	for (int i = 0; i < T.N; i++)
	{
		f << T.X[i].a << " ";
	}
	f << endl;
	f << T.P;
	f << endl;
	f << endl;
	f << endl;
}

void Task::print_2()
{
	ofstream f("out2.txt", ios_base ::app);

	for (int i = 0; i < T.N; i++)
	{
		f << T.X[i].a << " ";
	}
	f << endl;
	f << T.P;
	f << endl;
	f << endl;
	f << endl;
}
