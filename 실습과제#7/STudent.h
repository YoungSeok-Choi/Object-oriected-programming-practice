#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Subject.h"

using namespace std;

class Student
{
protected:
	string _StdName;
	int _Hakbun;
	int _SubNum;
	Subject* _Sub;
	float _AveGPA;

private:
	void InPutValue(int&);
	void InPutValue(string&);

public:
	void Initialize();
	void Initialize(string temp, int i, int j);
	void Remove();
	void InPutData();
	void PrintData() const;
	void CalcAveGPA();
	static int stnum;
};

#endif

