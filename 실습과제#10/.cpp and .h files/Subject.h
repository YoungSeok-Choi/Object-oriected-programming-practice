#ifndef SUBJECT_H
#define SUBJECT_H

#include "IOInterface.h"

class Subject : public IOInterface
{
protected:
	int _Hakjum;
	string _Grade;
	float _GPA;

	/*
	private:
		void InPutValue(int&);
		void InPutValue(string&);
	*/
	/* 위의 2개 함수 실습#9에서 삭제 */

	/*string _SubName*/
	/*위의 1개 멤버변수 실습#10에서 삭제*/

public:
	/* 실습#7 요구함수 */
	void InPutData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();

	/* 실습#8 요구함수 */
	Subject();
	void Modify();

	/*실습#10 요구함수*/
	virtual string GetName();
};

#endif