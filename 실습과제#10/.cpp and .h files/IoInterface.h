#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class IOInterface
{
protected:
	/*실습#10 추가 변수 및 가상함수*/
	string _Name;
	virtual string GetName() = 0;

	/*실습#9 멤버함수*/
	void InPutValue(int&);
	void InPutValue(string&);
	
};

#endif // !IOINTERFACE.H