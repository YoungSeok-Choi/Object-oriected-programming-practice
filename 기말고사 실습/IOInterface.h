#ifndef IOInterface_H
#define IOInterface_H
#include <iostream>
#include <string>

using namespace std;

class IOInterface
{
private:
	string _Name;

protected:
	virtual void InputValue(string&) = 0;

public:
	void InputValue(int&);
};


void IOInterface::InputValue(int& ref)
{
	cin >> ref;
}

void IOInterface::InputValue(string & ref){}
#endif // !IOInterface_H

