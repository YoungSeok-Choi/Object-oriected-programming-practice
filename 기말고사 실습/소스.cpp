#include "Student.h"
#include "IOInterface.h"
#include <iostream>
#include <string>

/*

파일 3개가 있다고 함, 한번만 제출 가능하니까 검토 다 끝내고 하세요
다른 창 뜨면 안됩니다. 

*/


void PrintMenu()
{
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 정보 입력\n";
	cout << "2. 학생 정보 출력\n";
	cout << "3. 프로그램 종료\n";
	cout << "원하는 기능을 입력하세요\n";
}

void InputData(Student* pSt, int StudentNum)
{
	int i;
	for (i = 0; i < StudentNum; i++)
	{
		cout << "* " << i + 1 << " 번 학생 : ";
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
			cout << "학생수 입력 : ";
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