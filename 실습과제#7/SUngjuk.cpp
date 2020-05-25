#include <iostream>
#include "Student.h"
#include "Subject.h"

using namespace std;


void ShowMenu(void);


int main()
{
	int command;
	int stdnum, i;
	Student *clas = NULL;

	do
	{
		ShowMenu();
		cin >> command;

		switch (command)
		{
		case 1:
		{
			cout << "\n����� �л����� ���� �Է��Ͻðڽ��ϱ�?\n";
			cout << "�л��� �Է�: ";
			cin >> stdnum;
			cin.ignore();
			clas = new Student[stdnum]; 
			for (i = 0; i < stdnum; i++)
				clas[i].InPutData();
			continue;
		}
		case 2:
		{
				cout << "\n\n\t��ü �л� ���� ����\n";
				for (i = 0; i < stdnum; i++)
					clas[i].PrintData();
			continue;
		}
		case 3:
		{
			cout << "���α׷� ����\n";
			continue;
		}
		default:
			cout << "�ùٸ� �޴� ��ȣ�� �Է��ϼ���.\n";
			continue;
		}

	} while (command != 3);

	for (i = 0; i < stdnum; i++)
		clas[i].Remove();
	
	delete [] clas;
	return 0;
}


void ShowMenu(void)
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. ���α׷� ����\n";
	cout << "\n���ϴ� ����� �Է��ϼ��� : ";
}
