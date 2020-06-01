#ifndef SUBJECT_H
#define SUBJECT_H

#include "IOInterface.h"

class Subject : public IOInterface
{
protected:
	string _SubName;
	int _Hakjum;
	string _Grade;
	float _GPA;

/*
private:
	void InPutValue(int&);
	void InPutValue(string&);
*/
/* 위의 2개 함수 실습#9에서 삭제 */

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
