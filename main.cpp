#include "test.h"

int main()
{
	system("mode con cols=90 lines=7");
	Test t;
	t.start();

	system("pause");
	return 0;
}