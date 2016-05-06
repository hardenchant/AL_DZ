// Accounting_fee.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "Street.h"
#include "clocale"
#include <memory>
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	Street street("Бауманская");
	Home first("3/5", 5);
	Home second("2", 7);
	Home third("44", 2);
	Home four("5", 3);
	
	street.InsertHouse(first);
	street.InsertHouse(second);
	street.InsertHouse(third);
	street.InsertHouse(four);

	
	//test.DeleteHouse("3/5");
	//cout << test << endl;

	//test[four.getName()].InsertServices("Repair");
	//test[third.getName()].InsertServices("Repair");
	//test[four.getName()].InsertServices("Electricity");
	//test[four.getName()].DeleteServices("Repair");
	//four.InsertServices("ColdWater");
	//second.InsertServices("ColdWater");
	//test.InsertAllBills();
	//second.SetPaid(700);

	//test.save();

	//test.SearchService("Repair");
	//test.SearchDebtors();
	//cout << test << endl;
	//second.save();
	//four.read("cppstudio.txt");
	//cout << four;

	//for (string v : history)
	//	cout << v << endl;

	int command;
	char buf[250], buf2[250];
	string temp1, temp3;
	int temp2;
	
	cout << "Выберите номер необходимой команды: \n\t1. Внесение нового дома в базу учета.\n\t2. Удаление дома из системы учета. \n\t3. Подключение/отключение услуги ЖКХ в конкретном доме.\n\t4. Изменение количества жильцов в конкретном доме.\n\t5. Выставление счета на оплату за месяц.\n\t6. Занесение данных об оплате услуг за месяц. \n\t7. Определение должников.\n\t8. Просмотр домов с подключенной услугой.\n\t9. Просмотр всех домов улицы. Для ВЫХОДА из программы нажмите 0.\n";
	cin >> command;

	do {
		switch (command) {
		case 1:
			cout << "Введите номер дома и количество жильцов: " << endl;
			scanf("%s %d", &temp1, &temp2);		
			street.InsertHouse(Home("9", 7));
			break;
		case 2:
			cout << "Введите номер дома: " << endl;
			cin >> temp1;
			street.DeleteHouse(temp1);
			break;
		case 3:
			cout << "Для ДОБАВЛЕНИЯ услуги введите 1_номер дома_навзвание услуги,\n для УДАЛЕНИЯ - 0_номер дома_название услуги.\n\tСписок услуг: HotWater, ColdWater, Electricity, Repair.\n" << endl;
			scanf("%d %s %s", &temp2, &buf, &buf2);
			temp1 = (const char*)buf;
			temp3 = (const char*)buf2;
			if (temp2 == 0) street[temp1].DeleteServices(temp3);
			else street[temp1].InsertServices(temp3);
			break;
		case 4:
			cout << "Введите номер дома и новое количество жильцов:" << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			street[temp1].SetTenants(temp2);
			break;
		case 5:
			street.InsertAllBills();
			break;
		case 6:
			cout << "Введите номер дома и внесенную сумму: " << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			street[temp1].SetPaid(temp2);
			break;
		case 7:
			street.SearchDebtors();
			break;
		case 8:
			cout << "Введите название услуги: " << endl;
			scanf("%s", &buf);
			temp1 = (const char*)buf;
			street.SearchService(temp1);
			break;
		case 9:
			cout << street << endl;
			break;
		case 0:
			//exit(0);
			break;
		}
		street.save();
		cin >> command;
	} while (command != 0);
	
	
	system("pause");
	return 0;
}

