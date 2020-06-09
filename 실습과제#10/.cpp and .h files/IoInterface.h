#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class IOInterface
{
protected:
	/*�ǽ�#10 �߰� ���� �� �����Լ�*/
	string _Name;
	virtual string GetName() = 0;

	/*�ǽ�#9 ����Լ�*/
	void InPutValue(int&);
	void InPutValue(string&);
	
};

#endif // !IOINTERFACE.H