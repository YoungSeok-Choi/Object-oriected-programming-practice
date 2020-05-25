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
			cout << "\n몇명의 학생정보 수를 입력하시겠습니까?\n";
			cout << "학생수 입력: ";
			cin >> stdnum;
			cin.ignore();
			clas = new Student[stdnum]; 
			for (i = 0; i < stdnum; i++)
				clas[i].InPutData();
			continue;
		}
		case 2:
		{
				cout << "\n\n\t전체 학생 성적 보기\n";
				for (i = 0; i < stdnum; i++)
					clas[i].PrintData();
			continue;
		}
		case 3:
		{
			cout << "프로그램 종료\n";
			continue;
		}
		default:
			cout << "올바른 메뉴 번호를 입력하세요.\n";
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
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 프로그램 종료\n";
	cout << "\n원하는 기능을 입력하세요 : ";
}
