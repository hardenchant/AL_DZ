// lab7_Deadlock.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#


using namespace std;
mutex mutex1, mutex2;

void ThreadA()
{
	mutex2.lock();
	cout << "Thread A" << endl;
	mutex1.lock();
	mutex2.unlock();
	mutex1.unlock();
}

void ThreadB()
{
	mutex1.lock();
	cout << "Thread B" << endl;
	mutex2.lock();
	mutex1.unlock();
	mutex2.unlock();
}

void ExecuteThreads()
{
	thread t1(ThreadA);
	thread t2(ThreadB);

	t1.join();
	t2.join();

	std::cout << "Finished" <<endl;
}

int main()
{
	ExecuteThreads();

	return 0;
}