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
	/* ���� 2�� �Լ� �ǽ�#9���� ���� */

	/*string _SubName*/
	/*���� 1�� ������� �ǽ�#10���� ����*/

public:
	/* �ǽ�#7 �䱸�Լ� */
	void InPutData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();

	/* �ǽ�#8 �䱸�Լ� */
	Subject();
	void Modify();

	/*�ǽ�#10 �䱸�Լ�*/
	virtual string GetName();
};

#endif