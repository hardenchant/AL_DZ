#include "vector"
#include "Home.h"



class Street:public Abstract {
private:
	vector<Home> Spisok;
	int amount;
public:
	Street(string name) : Abstract(name) { amount = 0; };
	void InsertHouse(Home&);
	void save();
	friend ostream& operator<<(ostream&, const Street&);
	void DeleteHouse(string);
	void SearchDebtors();
	void SearchService(string);
};

void Street::InsertHouse(Home& hm) {
	cout << "+";
	Spisok.push_back(hm);
	cout << "+";
	amount++;
}

ostream& operator<<(ostream& os, const Street& st) {
	os << "На улице " << st.Name << " находится " << st.amount << " домов:" << endl;
	for (auto v : st.Spisok)
		cout << v;
	return os;
}

void Street::save() {
	ofstream fout("cppstudio.txt");
	fout << *this;
	fout.close();
}

void Street::DeleteHouse(string name) {
	for (int i = 0; i < amount;i++)
	if (Spisok[i].getName() == name){
		amount--;
		//Spisok[i].~Home();
		Spisok.erase(Spisok.begin() + i);
		break;
	}
}

void Street::SearchDebtors() {
	cout << "Список должников: " << endl;
	for (int i = 0; i < amount; i++)
	if (Spisok[i].debt()>0)
		cout << "\tЖильцы дома номер " << Spisok[i].getName() << " должны " << Spisok[i].debt() << " рублей." << endl;
}

void Street::SearchService(string usl) {
	cout << "Список домов с подключенной данной услугой: " << endl;
	for (int i = 0; i < amount; i++) {
		for (auto v : Spisok[i].getServices()) {
			if (v.first == usl)
				cout << Spisok[i].getName() << endl;
			break;
		}
	}
}

