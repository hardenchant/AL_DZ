// ALARM.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>

using namespace std;
bool flag=false;

void alarm(int time){
	
	this_thread::sleep_for(chrono::milliseconds(time * 1000));

	cout << "ALARM!!!" << endl;
	flag = true;
	exit(0);
}

void echo(string word) {
	cout << word << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string command;
	
	while (!flag){
		cin >> command;
		if (command == "alarm"){
			int secs;
			cin >> secs;
			thread t1(alarm, secs);
			
			cout << "Alarm " << t1.get_id() << " is created" << endl;
			t1.detach();
		}
		if (command == "echo"){
			string s;
			cin >> s;
			thread t2(echo, ref(s));
			t2.detach();
		}
	}
	
	return 0;
}

