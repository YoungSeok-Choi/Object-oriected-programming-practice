#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

using namespace std;

class Subject
{
protected:
	string _SubName;
	int _Hakjum;
	string _Grade;
	float _GPA;

private:
	void InPutValue(int&);
	void InPutValue(string&);

public:
	/* �ǽ�#7 �䱸�Լ� */
	void InPutData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();

	/* �ǽ�#8 �䱸�Լ� */
	Subject();
	void Modify();
	string GetSubName();
};

#endif