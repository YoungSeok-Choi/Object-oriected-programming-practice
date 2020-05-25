#include "Student.h"

/*
�ǽ�#7 
�Լ� ����
*/
int Student::stnum = 0;

void Student::InPutValue(int & i)
	{
		int temp;
		cin >> temp;
		i = temp;
	}

void Student::InPutValue(string & temp)
	{
		getline(cin, temp);
	}

void Student::InPutData()
	{
		int i;
		string tmp;
		int hak, sub;
		Student::stnum++;
		cout << "\n* " << Student::stnum << " ��° �л� �̸��� ������� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InPutValue(tmp);
		cout << "�й� : ";
		InPutValue(hak);
		cout << "����� : ";
		InPutValue(sub);
		Initialize(tmp, hak, sub);
		_Sub = new Subject[sub];

		cin.ignore();
		cout << "\n* ������ ���� " << _SubNum << "���� �� �������, �������� �Է��ϼ���.\n";
		for (i = 0; i < Student::_SubNum; i++)
			_Sub[i].InPutData();
		CalcAveGPA();
	}

void Student :: PrintData() const
	{
		int i;

		cout << "====================================================\n";
		cout << "�̸� : " << _StdName << "  �й� : " << _Hakbun;
		cout << "\n====================================================\n";
		cout << "�����     ��������     ������     ��������\n";
		cout << "====================================================\n";

		for (i = 0; i < _SubNum; i++)
		{
			_Sub[i].PrintData();
			cout << "\n";
		}
			
			
		cout << "====================================================\n";
		cout << "\t\t\t\t ������� : " << _AveGPA;
		cout << "\n\n\n";
	}

void Student::CalcAveGPA()
{
	int i;
	_AveGPA = 0.0;

	for (i = 0; i < _SubNum; i++)
		_AveGPA += _Sub[i].GetGPA();
	
	_AveGPA = (float)_AveGPA / _SubNum;
}

void Student::Initialize(string temp, int i, int j)
{
	_StdName = temp;
	_Hakbun = i;
	_SubNum = j;
}

void Student::Initialize()
{
	_StdName = "�⺻��";
	_Hakbun = 20201234;
	_SubNum = 2;
}

void Student::Remove()
{
	delete [] _Sub;
}