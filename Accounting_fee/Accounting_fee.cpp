// Accounting_fee.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "Street.h"
#include "clocale"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	Street test("Победа");
	Home first("3/5", 5);
	Home second("2", 7);
	
	test.InsertHouse(first);

	test.InsertHouse(second);
	
	cout << test << endl;
	test.DeleteHouse("3/5");
	cout << test << endl;

	system("pause");
	return 0;
}

