#include "test.h"

void Test::start()
{
	ofstream clearss("sort_x_answ.txt");
	clearss.clear();
	clearss.close();
	clearss.open("sort_x.txt");
	clearss.clear();
	clearss.close();
	clearss.open("sort_y.txt");
	clearss.clear();
	clearss.close();
	clearss.open("intest.txt");
	clearss.clear();
	clearss.close();
	clearss.open("out1.txt");
	clearss.clear();
	clearss.close();
	clearss.open("out2.txt");
	clearss.clear();
	clearss.close();

	//ofstream out("out.txt");
	cout << setw(10) << "Complexity" << setw(10) <<  "Time" << setw(15) <<"Steps"<< setw(13) <<"Time/steps"<< setw(13) <<"Time/Teor."<< setw(10) <<"Steps*"<< setw(10) <<"Time*"<< setw(8) <<"P1/P2" << endl;
	
	cout.precision(3);
	// cc - сложность, h - теор сложность

	for (int l = 1; l <= 5; l++)
	{

		ifstream in("in.txt");
		unsigned long long steps_1 = 0, steps_2 = 0, cc = 0, h = 0, h_opt;
		time_1 = time_2 = 0;


			Generator::begin(l);
			ObjectData data1(in);
			in.close();
			in.open("in.txt");
			ObjectData data2(in);

			cc = data1.M + data1.N;
			h = data1.M * data1.N;

			Task solver(data1);
			Task_opt optimz_solver(data2);

			begin = clock();

			solver.init();
			while (solver.step()) {
				steps_1++;
			}
			solver.print_1();
			
			end = clock();
			

			time_1 += (double)(end - begin) / CLOCKS_PER_SEC;
			

			h_opt = data2.M * data2.M + 2 * data2.N*data2.N + data2.N;

			begin = clock();

			optimz_solver.init();
			while (optimz_solver.step()) {
				steps_2++;
			}
			end = clock();

			optimz_solver.print_2();

			time_2 += (double)(end - begin) / CLOCKS_PER_SEC;

			
			cout << setw(10) << cc << setw(10) << time_2 << setw(15) << steps_2 << setw(13) << time_2 / steps_2 << setw(13) << time_2 / h_opt << setw(10) <<(double)steps_1 / steps_2 << setw(10) << (double)time_1 / time_2 << setw(8) << (double)data1.P / data2.P << endl;
	}

}