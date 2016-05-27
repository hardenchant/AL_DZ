
#include "Home.h"
#include <sstream>

extern vector <string> history;

class Street :public Abstract {
private:
	vector<Home*> Spisok;
	int amount;
public:
	string getName() { return Name; }
	~Street() { Spisok.clear(); }
	Street(string name) : Abstract(name) { amount = 0; };
	void InsertHouse(Home*);
	void save();
	void read();
	friend ostream& operator<<(ostream&, const Street&);
	friend istream& operator>> (istream&, Street&);
	Home& operator[] (string);
	void DeleteHouse(string);
	void SearchDebtors();
	void SearchService(string);
	void InsertAllBills();
};

Home& Street:: operator[] (string name) {
	int save = amount;
	for (int i = 0; i < amount; i++)
		if (Spisok[i]->getName() == name)
		{
			return *Spisok[i]; break;
		}
	if (save == amount) throw "Дом с таким номером не найден.";
}

void Street::InsertHouse(Home *hm) {
	Spisok.push_back(hm);
	amount++;
	string temp = "К улице " + Name + " добавлен дом номер " + hm->getName();
	history.push_back(temp);
}

ostream& operator<<(ostream& os, const Street& st) {
	os << st.Name << " " << st.amount << endl;
	
	if (st.amount == 0) { throw "Список домов пуст."; }
	else {
		for (auto &v : st.Spisok)
			os << *v;
		return os;
	}
	return os;
}

istream& operator>> (istream& is, Street& st)
{
	is >> st.Name >> st.amount;
	for (int i = 0; i < st.amount; i++) {
		int p, b, t;
		string n, s;
		is >> n >> t >> p >> b;
		Home* temp = new Home(n, t);
		temp->SetPaid(p);
		while (is >> n) temp->InsertServices(n);
		st.Spisok.push_back(temp);
	}
	return is;
}

void Street::save() {
	ofstream fout("cppstudio.txt");
	if (!fout.is_open()) 
		throw "Файл для записи не может быть открыт!";
	else {
		fout << *this;
		fout.close();
	}
}

void Street::read() {
	ifstream fin("cppstudio.txt");
	fin >> *this;
	fin.close();
}

void Street::DeleteHouse(string name) {
	if (amount == 0) { throw "Список домов пуст."; }
	else {
		int save = amount;
		for (int i = 0; i < amount; i++)
			if (Spisok[i]->getName() == name) {
				amount--;
				//Spisok[i].~Home();
				Spisok.erase(Spisok.begin() + i);
				break;
			}
		if (save == amount) throw "Дом с таким номером не найден.";
		string temp = "С улицы " + Name + " удален дом номер " + name;
	}

}

void Street::SearchDebtors() {
	int save=0;
	cout << "Список должников: " << endl;
	string temp = "Подведен список должников: ";
	for (int i = 0; i < amount; i++)
		if (Spisok[i]->debt()>0) {
			cout << "\tЖильцы дома номер " << Spisok[i]->getName() << " должны " << Spisok[i]->debt() << " рублей." << endl;
			temp += Spisok[i]->getName() + " , ";
			save++;
		}
	if (save == 0) {
		throw "Список должников пуст";
		temp += " список должиков пуст.";
	}
	history.push_back(temp);
}

void Street::SearchService(string usl) {
	int save = 0;
	cout << "Список домов с подключенной данной услугой: " << endl;
	for (int i = 0; i < amount; i++) {
		for (auto v : Spisok[i]->getServices()) {
			if (v.first == usl) {
				cout << Spisok[i]->getName() << endl;
				save++;
			}
			break;
		}
	}
	if (save == 0) { throw "Не найдено домов с подключенной данной услугой."; }
}

void Street::InsertAllBills() {
	for (auto &v : Spisok)
		v->InsertBill();
}
