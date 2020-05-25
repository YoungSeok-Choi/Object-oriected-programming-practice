#include "Student.h"

/*
실습#7 
함수 정의
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
		cout << "\n* " << Student::stnum << " 번째 학생 이름과 과목수를 입력하세요.\n";
		cout << "이름 : ";
		InPutValue(tmp);
		cout << "학번 : ";
		InPutValue(hak);
		cout << "과목수 : ";
		InPutValue(sub);
		Initialize(tmp, hak, sub);
		_Sub = new Subject[sub];

		cin.ignore();
		cout << "\n* 수강한 과목 " << _SubNum << "개의 각 교과목명, 과목등급을 입력하세요.\n";
		for (i = 0; i < Student::_SubNum; i++)
			_Sub[i].InPutData();
		CalcAveGPA();
	}

void Student :: PrintData() const
	{
		int i;

		cout << "====================================================\n";
		cout << "이름 : " << _StdName << "  학번 : " << _Hakbun;
		cout << "\n====================================================\n";
		cout << "과목명     과목학점     과목등급     과목평점\n";
		cout << "====================================================\n";

		for (i = 0; i < _SubNum; i++)
		{
			_Sub[i].PrintData();
			cout << "\n";
		}
			
			
		cout << "====================================================\n";
		cout << "\t\t\t\t 평균평점 : " << _AveGPA;
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
	_StdName = "기본값";
	_Hakbun = 20201234;
	_SubNum = 2;
}

void Student::Remove()
{
	delete [] _Sub;
}