#include <iostream>
#include "Student.h"
#include "Subject.h"

using namespace std;

/*7장 요구함수 정의*/
inline void InputValue(int&);
inline void InputValue(string&);
inline void ShowMenu(void);
void PrintAllData(const Student* pSt, int StudentNum);
void InputData(Student* pSt, int StudentNum);
/*8장 요구함수 정의*/
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
			cout << "\n몇명의 학생정보 수를 입력하시겠습니까?\n";
			cout << "학생수 입력: ";
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
			cout << "프로그램 종료\n";
			continue;
		}
		default:
			cout << "올바른 메뉴 번호를 입력하세요.\n";
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
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 정보 수정\n";
	cout << "4. 프로그램 종료\n";
	cout << "\n원하는 기능을 입력하세요 : ";
}

void PrintAllData(const Student* pSt, int StudentNum)
{
	int i;

	cout << "\n\n\t전체 학생 성적 보기\n";
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
	cout << "검색 할 학생 이름 : ";
	InputValue(name);
	for (i = 0; i < StudentNum; i++)
	{
		comp = pSt[i].GetStdName();
		if (name == comp)
			return &pSt[i];
	}
	cout << "\n해당하는 이름의 학생은 존재하지 않습니다\n";
	return NULL;
}

void Modify(Student* pSt, int StudentNum)
{
	pSt->Modify();
}