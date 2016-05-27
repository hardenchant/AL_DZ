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

	street.read();

	//for (string v : history) //История сессии
	//	cout << v << endl;

	int command;
	char buf[250], buf2[250];
	string temp1, temp3;
	int temp2;

	cout << "Сохранение и восстановление данных ведется автоматически.\n\nВыберите номер необходимой команды: \n\t1. Внесение нового дома в базу учета.\n\t2. Удаление дома из системы учета. \n\t3. Подключение/отключение услуги ЖКХ в конкретном доме.\n\t4. Изменение количества жильцов в конкретном доме.\n\t5. Выставление счета на оплату за месяц.\n\t6. Занесение данных об оплате услуг за месяц. \n\t7. Определение должников.\n\t8. Просмотр домов с подключенной услугой.\n\t9. Просмотр всех домов улицы. Для ВЫХОДА из программы нажмите 0.\n";
	
	try {
		cin >> command;
		if (command != 1 && command != 2 && command != 3 && command != 4 && command != 5 && command != 6 && command != 7 && command != 8 && command != 9 && command != 0) {
			throw "Введен неверный номер команды.";
		}
	}
	catch (char* str) {
		cout << str << endl;
		cout << "Введите следующую команду: ";
		command = -1;
	}
	if (command == -1) cin >> command;
	do {
		
		if (command == 1) {
			cout << "Введите номер дома и количество жильцов: " << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			Home* temp = new Home(temp1, temp2);
			street.InsertHouse(temp);
		}
		if (command == 2) {
			cout << "Введите номер дома: " << endl;
			cin >> temp1;
			try { street.DeleteHouse(temp1); }
			catch (char* str) { cout << str<<endl; }
		}
		if (command == 3) {
			cout << "Для ДОБАВЛЕНИЯ услуги введите 1_номер дома_название услуги,\n для УДАЛЕНИЯ - 0_номер дома_название услуги.\n\tСписок услуг: HotWater, ColdWater, Electricity, Repair.\n" << endl;
			scanf("%d %s %s", &temp2, &buf, &buf2);
			temp1 = (const char*)buf;
			temp3 = (const char*)buf2;
			if (temp2 == 0)
			{
				try { street[temp1].DeleteServices(temp3); }
				catch (char* str) { cout << str<<endl; }
			}
			else
			{
				try { street[temp1].InsertServices(temp3); }
				catch (char* str) { cout << str << endl; }
			}
		}
		if (command == 4) {
			cout << "Введите номер дома и новое количество жильцов:" << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			try { street[temp1].SetTenants(temp2); }
			catch (char* str) {cout << str << endl;}
		}
		if (command == 5) {
			street.InsertAllBills();
		}
		if (command == 6) {
			cout << "Введите номер дома и внесенную сумму: " << endl;
			scanf("%s %d", &buf, &temp2);
			temp1 = (const char*)buf;
			try { street[temp1].SetPaid(temp2); }
			catch (char* str) {cout << str << endl;}
		}
		if (command == 7) {
			try { street.SearchDebtors(); }
			catch (char* str) { cout << str << endl; }
		}
		if (command == 8) {
			cout << "Введите название услуги: " << endl;
			scanf("%s", &buf);
			temp1 = (const char*)buf;
			try { street.SearchService(temp1); }
			catch (char* str) { cout << str << endl; }
		}
		if (command == 9) {
			try { cout << street << endl; }
			catch (char* str) { cout << str << endl; }
		}
		if (command == 0)
			exit(0);
			
		try { street.save(); }
		catch (char*str) { cout << str << endl; }
		cout << "Введите следующую команду: ";
		try { cin >> command;
		if (command != 1 && command != 2 && command != 3 && command != 4 && command != 5 && command != 6 && command != 7 &&command != 8 && command != 9 && command != 0) {
			throw "Введен неверный номер команды.";
		}
		}
		catch(char* str) { cout << str << endl;
		cout << "Введите следующую команду: ";
		command = -1;
		}
		if (command == -1) cin >> command;
	} while (command != 0);

	system("pause");
	return 0;
}

