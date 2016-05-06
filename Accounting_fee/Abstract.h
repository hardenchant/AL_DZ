#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector <string> history;

class Abstract {
protected:
	string Name;
public:
	Abstract() {}
	string getName() {return Name; }
	Abstract(string);
	virtual void save() = 0;
};
Abstract::Abstract(string name) { Name = name; };