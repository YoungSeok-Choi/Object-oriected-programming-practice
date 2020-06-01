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
	/* 실습#7 요구함수 */
	void InPutData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();

	/* 실습#8 요구함수 */
	Subject();
	void Modify();
	string GetSubName();
};

#endif