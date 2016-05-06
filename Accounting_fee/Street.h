//#include "vector"
#include "Home.h"

extern vector <string> history;

class Street:public Abstract {
private:
	vector<Home*> Spisok;
	int amount;
public:
	~Street(){ Spisok.clear(); }
	Street(string name) : Abstract(name) { amount = 0; };
	void InsertHouse(Home&);
	void save();
	friend ostream& operator<<(ostream&, const Street&);
	friend istream& operator>> (istream&, Street&);
	Home& operator[] (string);
	void DeleteHouse(string);
	void SearchDebtors();
	void SearchService(string);
	void InsertAllBills();
};

Home& Street:: operator[] (string name) {
	for (int i = 0; i < amount; i++)
	if (Spisok[i]->getName() == name)
	{
		return *Spisok[i]; break;
	}
}

void Street::InsertHouse(Home& hm) {
	Spisok.push_back(&hm);
	amount++;
	string temp = "К улице " + Name + " добавлен дом номер " + hm.getName();
	history.push_back(temp);
}

ostream& operator<<(ostream& os, const Street& st) {
	os << st.Name << " " <<  st.amount << endl;
	for (auto &v : st.Spisok)
		os << *v;
	return os;
}

istream& operator>> (istream& is, Street& st)
{
	is >> st.Name >> st.amount;
	for (int i = 0; i < st.amount; i++) {
		Home& temp = Home();
		is >> temp;
	//	st.Spisok.push_back(std::move(temp));
	}
	return is;
}

void Street::save() {
	ofstream fout("cppstudio.txt");
	fout << *this;
	fout.close();
}

void Street::DeleteHouse(string name) {
	for (int i = 0; i < amount;i++)
	if (Spisok[i]->getName() == name){
		amount--;
		//Spisok[i].~Home();
		Spisok.erase(Spisok.begin() + i);
		break;
	}
	string temp = "С улицы " + Name + " удален дом номер " + name;

}

void Street::SearchDebtors() {
	cout << "Список должников: " << endl;
	string temp = "Подведен список должников: ";
	for (int i = 0; i < amount; i++)
	if (Spisok[i]->debt()>0) {
		cout << "\tЖильцы дома номер " << Spisok[i]->getName() << " должны " << Spisok[i]->debt() << " рублей." << endl;
		temp += Spisok[i]->getName() + " , " ;
	}
	history.push_back(temp);
}

void Street::SearchService(string usl) {
	cout << "Список домов с подключенной данной услугой: " << endl;
	for (int i = 0; i < amount; i++) {
		for (auto v : Spisok[i]->getServices()) {
			if (v.first == usl)
				cout << Spisok[i]->getName() << endl;
			break;
		}
	}
}

void Street::InsertAllBills() {
	for (auto &v : Spisok)
		v->InsertBill();
}
