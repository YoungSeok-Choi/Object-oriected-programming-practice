#include <iostream>
#include "Student.h"
#include "Subject.h"

using namespace std;

/*7�� �䱸�Լ� ����*/
inline void InputValue(int&);
inline void InputValue(string&);
inline void ShowMenu(void);
void PrintAllData(const Student* pSt, int StudentNum);
void InputData(Student* pSt, int StudentNum);
/*8�� �䱸�Լ� ����*/
Student* StdSearch(Student*, int);
void Modify(Student*, int);


int main()
{
	int command;
	int stdnum, i;
	Student* clas = NULL;
	Student* temp = NULL;

	do
	{
		ShowMenu();
		InputValue(command);
		switch (command)
		{
		case 1:
		{
			cout << "\n����� �л����� ���� �Է��Ͻðڽ��ϱ�?\n";
			cout << "�л��� �Է�: ";
			InputValue(stdnum);
			cin.ignore();
			clas = new Student[stdnum];
			InputData(clas, stdnum);
			continue;
		}
		case 2:
		{
			PrintAllData(clas, stdnum);
			continue;
		}
		case 3:
		{
			temp = StdSearch(clas, stdnum);
			if (temp != NULL)
			{
				Modify(temp, stdnum);
				continue;
			}
			else
				continue;
		}
		case 4:
		{
			cout << "���α׷� ����\n";
			continue;
		}
		default:
			cout << "�ùٸ� �޴� ��ȣ�� �Է��ϼ���.\n";
			continue;
		}
	} while (command != 4);

	delete[] clas;
	return 0;
}

inline void InputValue(int& temp)
{
	cin >> temp;
}

inline void InputValue(string& temp)
{
	getline(cin, temp);
}

inline void ShowMenu(void)
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� ���� ����\n";
	cout << "4. ���α׷� ����\n";
	cout << "\n���ϴ� ����� �Է��ϼ��� : ";
}

void PrintAllData(const Student* pSt, int StudentNum)
{
	int i;

	cout << "\n\n\t��ü �л� ���� ����\n";
	for (i = 0; i < StudentNum; i++)
		pSt[i].PrintData();
}

void InputData(Student* pSt, int StudentNum)
{
	int i;

	for (i = 0; i < StudentNum; i++)
		pSt[i].InPutData();
}

Student* StdSearch(Student* pSt, int StudentNum)
{
	int i;
	string name, comp;
	cin.ignore();
	cout << "�˻� �� �л� �̸� : ";
	InputValue(name);
	for (i = 0; i < StudentNum; i++)
	{
		comp = pSt[i].GetStdName();
		if (name == comp)
			return &pSt[i];
	}
	cout << "\n�ش��ϴ� �̸��� �л��� �������� �ʽ��ϴ�\n";
	return NULL;
}

void Modify(Student* pSt, int StudentNum)
{
	pSt->Modify();
}