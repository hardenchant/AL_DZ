#include "Abstract.h"
#include "Map"
#include <fstream>

using namespace std;

map <string, int> services = {  { "Electricity", 37 },
								{ "HotWater", 40 },
								{ "ColdWater", 15 },
								{ "Repair", 20 } };

class Home : public Abstract {
private:
	int tenants;
	map <string, int> this_services;
	int bill;
	int paid;
public:
	Home(string num, int ten) : Abstract(num) { tenants = ten; paid = 0; };
	~Home() { this_services.clear(); };
	void InsertBill();
	void SetPaid(int);
	void InsertServices(string);
	friend ostream& operator<<(ostream&, const Home&);
	friend istream& operator>> (istream&, Home&);
	void SetTenants(int);
	void save();
	int debt();
	map<string, int> getServices() { return this_services; }
	
};
ostream& operator<<(ostream& os, const Home& hm){
	os <<  hm.Name << endl <<  hm.tenants << endl <<  hm.paid << endl;
	return os;
}

istream& operator>> (istream& is, Home& hm){
	is >> hm.Name >> hm.tenants >> hm.paid;
	return is;
}

void Home::InsertServices(string usl){
	this_services[usl] = services[usl];
}

void Home::InsertBill() {
	for (auto v : this_services) 
		bill += v.second*tenants;
	cout << "Счет дома номер " << Name << " составляет " << bill << endl;
}

void Home::SetPaid(int money) {
	paid += money;
	cout << "На данный момент за услуги дома номер " << Name << " внесено " << paid << endl;
}

void Home::SetTenants(int num) {
	tenants = num;
}

void Home::save() {
	ofstream fout("cppstudio.txt");
	fout << *this;
	fout.close();
}

int Home::debt() {
	return bill - paid;
}
