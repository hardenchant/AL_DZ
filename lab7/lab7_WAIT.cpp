// lab7_WAIT.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;
condition_variable data_cond;
mutex m;
bool flag=false;

void f1(void) {
	
		unique_lock<mutex> lock(m, defer_lock);
		m.lock();
		for (int j = 0; j < 50; j++){
			this_thread::sleep_for(std::chrono::milliseconds(10));
			cout << "aaaaa";
		}
		
		flag = true;
		data_cond.notify_one();
		m.unlock();
		for (int j = 0; j < 50; j++){
			this_thread::sleep_for(std::chrono::milliseconds(10));
			cout << "aaaaa";
		}
}

void f2(void) {
	unique_lock<mutex> lock(m);
	data_cond.wait(lock, [] { return flag; });
	for (int i = 0; i < 100; i++) {	
			this_thread::sleep_for(std::chrono::milliseconds(10));
			cout << "bbbbb";
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
