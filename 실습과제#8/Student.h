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
	// �ǽ�7 �䱸�Լ�
	void InPutData();
	void PrintData() const;
	float CalcAveGPA(); // �ǽ�#8���� ��ȯ�� ����
	static int stnum;

	/*�ǽ� 8�䱸�Լ�*/
	Subject* SubSearch();
	void Modify();
	string GetStdName();
	Student();
	~Student();
};

#endif


