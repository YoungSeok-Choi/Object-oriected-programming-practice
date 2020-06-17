#include "Student.h"
#include "IOInterface.h"
#include <iostream>
#include <string>

/*

���� 3���� �ִٰ� ��, �ѹ��� ���� �����ϴϱ� ���� �� ������ �ϼ���
�ٸ� â �߸� �ȵ˴ϴ�. 

*/


void PrintMenu()
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. �л� ���� ���\n";
	cout << "3. ���α׷� ����\n";
	cout << "���ϴ� ����� �Է��ϼ���\n";
}

void InputData(Student* pSt, int StudentNum)
{
	int i;
	for (i = 0; i < StudentNum; i++)
	{
		cout << "* " << i + 1 << " �� �л� : ";
		pSt[i].PutName();
	}
}

void PrintData(Student& rSt)
{
	string name = rSt.GetName();
	cout << name << "\n";
}

int main()
{
	int i;
	Student* St = 0;
	IOInterface *IO = 0;

	int StdNum = 0;
	int selected_menu = 0;

	while (selected_menu != 3)
	{
		PrintMenu();
		IO->InputValue(selected_menu);
		cout << endl;

		switch (selected_menu)
		{
		case 1:
		{
			cout << "�л��� �Է� : ";
			IO->InputValue(StdNum);
			St = new Student[StdNum];
			InputData(St, StdNum);
			break;
		}
		case 2:
		{
			for (i = 0; i < StdNum; i++)
			{
				string temp1 = St[i].GetName();
				cout << temp1 << "\n";
			}
			break;
		}
		case 3:
		{
			break;
		}
		default:
			cout << "Error" << endl;
			break;
		}
	}

	return 0;
}