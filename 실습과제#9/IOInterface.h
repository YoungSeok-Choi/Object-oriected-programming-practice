#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class IOInterface
{
protected:
	void InPutValue(int&);
	void InPutValue(string&);
};

#endif // !IOINTERFACE.H