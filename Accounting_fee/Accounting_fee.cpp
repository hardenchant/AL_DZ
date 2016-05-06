// Accounting_fee.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "Street.h"
#include "clocale"
#include <memory>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	Street test("Победа");
	Home first("3/5", 5);
	Home second("2", 7);
	Home third("44", 2);
	Home four("5", 3);
	
	test.InsertHouse(first);
	test.InsertHouse(second);
	test.InsertHouse(third);
	test.InsertHouse(four);

	cout << test << endl;
	test.DeleteHouse("3/5");
	//cout << test << endl;

	test[four.getName()].InsertServices("Repair");
	//four.InsertServices("ColdWater");
	//second.InsertServices("ColdWater");
	test.InsertAllBills();
	second.SetPaid(700);

	test.save();

	//test.SearchService("Repair");
	//test.SearchDebtors();
	//cout << test << endl;
	//second.save();
	//four.read("cppstudio.txt");
	//cout << four;

	for (string v : history)
		cout << v << endl;

	int command;
	string temp1;
	int temp2;
	Street street("Бауманская");
	cout << "Выберите номер необходимой команды: \n\t1. Внесение нового дома в базу учета.\n\t2. Удаление дома из системы учета. \n\t3. Подключение/отключение услуги ЖКХ в конкретном доме.\n\t4. Изменение количества жильцов в конкретном доме.\n\t5. Выставление счета на оплату за месяц.\n\t6. Занесение данных об оплате услуг за месяц. \n\t7. Определение должников.\n\t8. Просмотр домов с подключенной услугой.\n\t Для ВЫХОДА из программы нажмите 0.\n";
	
	cin >> command;

	shared_ptr<Home> temp;
	
	
	do {
		switch (command) {
		case 1:
			cout << "Введите номер дома и количество жильцов: " << endl;
			//scanf("%s %d", &temp1, &temp2);		
			
			//street.InsertHouse(*temp);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			//exit(0);
			break;
		cin >> command;
		}
	} while (command != 0);
	
	cout << street;
	system("pause");
	return 0;
}

