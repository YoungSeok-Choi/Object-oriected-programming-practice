#include "IOInterface.h"


void IOInterface::InPutValue(int& i)
{
	int temp;
	cin >> temp;
	i = temp;
}

void IOInterface::InPutValue(string& temp)
{
	getline(cin, temp);
}
