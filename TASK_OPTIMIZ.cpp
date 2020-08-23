#include "TASK_OPTIMIZ.h"

void Task_opt::pswap(Pair & A, Pair & B)
{
	Pair temp = A;
	A = B;
	B = temp;
}
int Task_opt::Step_Sort_X()
{
	if (i >= T.N)
	{
		i = 0; j = 0; algostate++;

		//ofstream test("sort_x.txt", ios_base::app);
		//test << T.N << endl;
		//for (int c = 0; c < T.N; c++)
		//{
		//	test << T.X[c].a << " ";
		//}
		//test << endl;
		//for (int c = 0; c < T.N; c++)
		//{
		//	test << T.X[c].b << " ";
		//}
		//test << endl << endl;


		return 0;
	}
	

	if (j >= T.N - 1)
	{
		i++; j = 0;
	}
	else
	{
		if (T.X[j].a > T.X[j + 1].a)
		{
			pswap(T.X[j], T.X[j + 1]);
		}
		j++;
	}

		/*
	for (int i = 0; i < T.N; i++)
	{
		for (int j = 0; j < T.N - 1; j++)
		{
			if (T.X[j].a > T.X[j + 1].a)
			{
				pswap(T.X[j], T.X[j + 1]);
			}
		}
	}
	i = 0; algostate++;*/

	
	return 1;
}
int Task_opt::Step_Sort_Y()
{
	if (i >= T.M)
	{
		i = 0; j = 0; algostate++;

		//ofstream test("sort_y.txt", ios_base::app);
		//test << T.M << endl;
		//for (int c = 0; c < T.M; c++)
		//{
		//	test << T.Y[c].a << " ";
		//}
		//test << endl;
		//for (int c = 0; c < T.M; c++)
		//{
		//	test << T.Y[c].b << " ";
		//}
		//test << endl << endl;

		return 0;
	}


	if (j >= T.M - 1)
	{
		i++; j = 0;
	}
	else
	{
		if (T.Y[j].a > T.Y[j + 1].a)
		{
			pswap(T.Y[j], T.Y[j + 1]);
		}
		j++;
	}


	//for (int i = 0; i < T.M; i++)
	//{
	//	for (int j = 0; j < T.M - 1; j++)
	//	{
	//		if (T.Y[j].a > T.Y[j + 1].a)
	//		{
	//			pswap(T.Y[j], T.Y[j + 1]);
	//		}
	//	}
	//}
	//i = j = 0; algostate++;



	return 1;
}
int Task_opt::Step_Distribution()
{
	if (i >= T.N)
	{
		exit = false;
		i = 0;
		algostate++;
		return 0;
	}


	if (T.X[i].a < T.Y[j].a)
	{
		T.X[i].a = T.Y[j].b + 1;
		j++; i++;
		T.P++;
	}
	else if (j < T.M)
		j++;
	else
	{
		for (int c = i; c < T.N; c++)
		{
			T.X[c].a = 0;
		}
		i = T.N;
	}

	return 1;
}
int Task_opt::Step_Sort_index()
{
	if (i >= T.N)
	{
		i = 0; j = 0; algostate++;

		//qofstream test("sort_x_answ.txt", ios_base::app);
		//test << T.N << endl;
		//for (int c = 0; c < T.N; c++)
		//{
		//	test << T.X[c].a << " ";
		//}
		//test << endl;
		//for (int c = 0; c < T.N; c++)
		//{
		//	test << T.X[c].b << " ";
		//}
		//test << endl << endl;

		return 0;
	}


	if (j >= T.N - 1)
	{
		i++; j = 0;
	}
	else
	{
		if (T.X[j].b > T.X[j + 1].b)
		{
			pswap(T.X[j], T.X[j + 1]);
		}
		j++;
	}
/*
	for (int i = 0; i < T.N; i++)
	{
		for (int j = 0; j < T.N - 1; j++)
		{
			if (T.X[j].b > T.X[j + 1].b)
			{
				pswap(T.X[j], T.X[j + 1]);
			}
		}
	}*/

	return 1;
}
void Task_opt::init()
{
	exit = false;
	i = 0;
	algostate = 0;
}
int Task_opt::step()
{
	if (algostate == 0)
	{
		Step_Sort_X();
	}
	else if (algostate == 1)
	{
		Step_Sort_Y();
	}
	else if (algostate == 2)
	{
		Step_Distribution();
	}
	else if (algostate == 3)
	{
		return Step_Sort_index();
	}
	return 1;
}
