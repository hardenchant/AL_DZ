#include "string"
#include "iostream"


using namespace std;

class Abstract {
protected:
	string Name;
public:
	Abstract(string);
	~Abstract() { cout << "DESTROY" << endl; }
	virtual void save() = 0;
};
Abstract::Abstract(string name) { Name = name; };