#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>
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
	// 실습7 요구함수
	void InPutData();
	void PrintData() const;
	float CalcAveGPA(); // 실습#8에서 반환형 변경
	static int stnum;

	/*실습 8요구함수*/
	Subject* SubSearch();
	void Modify();
	string GetStdName();
	Student();
	~Student();
};

#endif


