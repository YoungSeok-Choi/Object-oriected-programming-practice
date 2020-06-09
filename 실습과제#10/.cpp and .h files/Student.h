#ifndef STUDENT_H
#define STUDENT_H


#include "IOInterface.h"
#include "Subject.h"

class Student : public IOInterface
{
protected:
	int _Hakbun;
	int _SubNum;
	Subject* _Sub;
	float _AveGPA;

	/*
	private:
		void InPutValue(int&);
		void InPutValue(string&);
	*/
	/* 위의 2개 함수 실습#9에서 삭제 */

	/*string _StdName*/
	/*위의 1개 멤버변수 실습#10에서 삭제*/


public:
	// 실습7 요구함수
	void InPutData();
	void PrintData() const;
	float CalcAveGPA(); // 실습#8에서 반환형 변경
	static int stnum;

	/*실습 8요구함수*/
	Subject* SubSearch();
	void Modify();
	Student();
	~Student();

	/*실습#10 요구함수*/
	virtual string GetName();

};

#endif