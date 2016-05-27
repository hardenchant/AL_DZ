#include "Abstract.h"
#include "Map"
#include <fstream>

using namespace std;
extern vector <string> history;

map <string, int> services = { { "Electricity", 37 },
{ "HotWater", 40 },
{ "ColdWater", 15 },
{ "Repair", 20 },
{"-", 0} };

class Home : public Abstract {
private:
	int tenants;
	map <string, int> this_services;
	int bill;
	int paid;
public:
	string getName() { return Name; }
	Home() {  }
	Home(string num, int ten) : Abstract(num) {
		tenants = ten; paid = 0; bill = 0;
	};
	~Home() { this_services.clear(); };
	void InsertBill();
	void SetPaid(int);
	void InsertServices(string);
	void DeleteServices(string);
	friend ostream& operator<<(ostream&, const Home&);
	friend istream& operator>> (istream&, Home&);
	void SetTenants(int);
	void save();
	void Set(string, int);
	void read(string);
	int debt();
	map<string, int> getServices() { return this_services; }

};
ostream& operator<<(ostream& os, const Home& hm) {
	os << hm.Name << endl << hm.tenants << endl << hm.paid << endl << hm.bill << endl;
	for (auto v : hm.this_services) {
		os << v.first << " ";
	}
	os << endl;
	return os;
}

istream& operator>> (istream& is, Home& hm) {
	is >> hm.Name >> hm.tenants >> hm.paid >> hm.bill;
	return is;
}

void Home::Set(string name, int num) {
	Name = name;
	tenants = num;
	bill = paid = 0;
}

void Home::InsertServices(string usl) {
	this_services[usl] = services[usl];
	string temp = "К дому номер " + Name + " подключена услуга " + usl;
	history.push_back(temp);
}
void Home::DeleteServices(string usl) {
	auto it = this_services.find(usl);
	this_services.erase(it);
	string temp = "В доме номер " + Name + " отключена услуга " + usl;
	history.push_back(temp);
}
void Home::InsertBill() {
	for (auto v : this_services)
		bill += v.second*tenants;
	cout << "Счет дома номер " << Name << " составляет " << bill << endl;
	string temp = "Выставлен счет для дома номер " + Name + " в размере " + to_string(bill);
	history.push_back(temp);
}

void Home::SetPaid(int money) {
	paid += money;
	cout << "На данный момент за услуги дома номер " << Name << " внесено " << paid << endl;
	string temp = "За услуги дома номер " + Name + " внесено " + to_string(money) + " рублей.";
	history.push_back(temp);
}

void Home::SetTenants(int num) {
	tenants = num;
	string tt = "Количество жильцов дома номер " + Name + " изменено на " + to_string(num);
	history.push_back(tt);
}

void Home::save() {
	ofstream fout("cppstudio.txt");
	fout << *this;
	fout.close();
}

void Home::read(string name) {
	ifstream fin("cppstudio.txt");
	fin >> *this;
	fin.close();
}

int Home::debt() {
	return bill - paid;
}
