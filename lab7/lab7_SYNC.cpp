// lab7_SYNC.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>


using namespace std;
mutex m;

void f1(void) {
	for (int i = 0; i < 25; i++) {
		lock_guard<mutex> lock(m);
		for (int j = 0; j < 4; j++){
			this_thread::sleep_for(std::chrono::milliseconds(10));
			cout << "aaaaa";
		}
	}
}

void f2(void) {
	for (int i = 0; i < 25; i++) {
		lock_guard<mutex> lock(m);
		for (int j = 0; j < 4; j++){
			this_thread::sleep_for(std::chrono::milliseconds(10));
			cout << "bbbbb";
		}
	}
}

int main(void) {
	thread t1(f1);
	thread t2(f2);

	t1.join();
	t2.join();
	cout << endl;

	system("pause");
	return 0;
}

