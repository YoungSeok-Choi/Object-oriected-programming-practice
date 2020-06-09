#include "Student.h"

/*
�ǽ�#7
�Լ� ����
*/
int Student::stnum = 0;

/* privates */
/*
void Student::InPutValue(int& i)
{
	int temp;
	cin >> temp;
	i = temp;
}
*/

/*
void Student::InPutValue(string& temp)
{
	getline(cin, temp);
}
*/
/* ���� 2�� �Լ� �ǽ�#9���� ���� */

/* publics */
void Student::InPutData()
{
	int i;
	string tmp;
	int hak, sub;

	Student::stnum++;

	cout << "\n* " << Student::stnum << " ��° �л� �̸��� ������� �Է��ϼ���.\n";
	cout << "�̸� : ";
	IOInterface::InPutValue(tmp);
	_Name = tmp;

	cout << "�й� : ";
	IOInterface::InPutValue(hak);
	_Hakbun = hak;

	cout << "����� : ";
	IOInterface::InPutValue(sub);
	_SubNum = sub;
	_Sub = new Subject[sub];
	cin.ignore();

	cout << "\n* ������ ���� " << _SubNum << "���� �� �������, �������� �Է��ϼ���.\n";
	for (i = 0; i < Student::_SubNum; i++)
		_Sub[i].InPutData();

	_AveGPA = CalcAveGPA();
}

void Student::PrintData() const
{
	int i;

	cout << "====================================================\n";
	cout << "�̸� : " << _Name << "  �й� : " << _Hakbun;
	cout << "\n====================================================\n";
	cout << "�����     ��������     ������     ��������\n";
	cout << "====================================================\n";

	cout.precision(2);
	cout << fixed;

	for (i = 0; i < _SubNum; i++)
	{
		_Sub[i].PrintData();
		cout << "\n";
	}


	cout << "====================================================\n";
	cout << "\t\t\t\t ������� : " << _AveGPA;
	cout << "\n\n\n";
}

float Student::CalcAveGPA()
{
	int i;
	_AveGPA = 0.0;

	float sum = 0.0;

	for (i = 0; i < _SubNum; i++)
		sum += _Sub[i].GetGPA();

	return (float)sum / _SubNum;
}

/*
�ǽ�#8
�Լ� ����
*/

/* publics */
Student::Student()
{
	_Name = "ȫ�浿";
	_Hakbun = 2019000000;
	_SubNum = 1;
	_Sub = new Subject[_SubNum];
}

Student::~Student()
{
	delete[] _Sub;
}

void Student::Modify()
{
	cout << "\n����(�л�����/��������): ";
	string type;
	IOInterface::InPutValue(type);

	if (type == "�л�����")
	{
		cout << "\n* (" << _Name << ", " << _Hakbun << ")�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		IOInterface::InPutValue(_Name);
		cout << "\n";
		cout << "�й� : ";
		IOInterface::InPutValue(_Hakbun);
		cout << "\n\n";
	}
	else if (type == "��������")
	{
		Subject* temp = NULL;
		temp = SubSearch();

		if (temp == NULL)
		{
			cout << "�ش� ������ �������� �ʽ��ϴ�. �ٽ� �˻��Ͽ� �ֽʽÿ�\n";
			return;
		}
		else
		{
			temp->Modify();
			_AveGPA = CalcAveGPA();
			return;
		}
	}
	else
	{
		cout << "\n�ùٸ� �޴��� �Է��ϼ���\n";
		return;
	}
	return;
}

string Student::GetName()
{
	return _Name;
}
/*���� �Լ� �ǽ�#10 ���� ������*/

Subject* Student::SubSearch()
{
	int i;
	string tempsub, comp;
	cout << "�˻� �� ���� �̸� : ";
	IOInterface::InPutValue(tempsub);

	for (i = 0; i < _SubNum; i++)
	{
		comp = _Sub[i].GetName();
		if (comp == tempsub)
			return &_Sub[i];
	}
	return NULL;
}