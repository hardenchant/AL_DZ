#include <iostream>
#include <thread>


using namespace std;

void f1(void) {
	for (int i = 0; i < 100; i++) {
		this_thread::sleep_for(std::chrono::milliseconds(10));
		cout << "aaaaa";
	}
}

void f2(void) {
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

