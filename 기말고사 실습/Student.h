#ifndef STUDENT_H
#define STUDENT_H
#include "IOInterface.h"
#include <iostream>
#include <string>
using namespace std;

class Student : private IOInterface
{
private:
	string _Name;

public:
	Student();
	void InputValue(string&);
	void PutName();
	string GetName();
};

Student::Student()
{
	_Name = "Mike";
}

void Student::InputValue(string& ref)
{
	getline(cin, ref);
	if (ref.empty()) getline(cin, ref);
	
}
void Student::PutName()
{
	cin >> _Name;
}

string Student::GetName()
{
	return _Name;
}
#endif // !STUDENT_H
