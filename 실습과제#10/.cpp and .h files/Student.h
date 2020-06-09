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
	/* ���� 2�� �Լ� �ǽ�#9���� ���� */

	/*string _StdName*/
	/*���� 1�� ������� �ǽ�#10���� ����*/


public:
	// �ǽ�7 �䱸�Լ�
	void InPutData();
	void PrintData() const;
	float CalcAveGPA(); // �ǽ�#8���� ��ȯ�� ����
	static int stnum;

	/*�ǽ� 8�䱸�Լ�*/
	Subject* SubSearch();
	void Modify();
	Student();
	~Student();

	/*�ǽ�#10 �䱸�Լ�*/
	virtual string GetName();

};

#endif