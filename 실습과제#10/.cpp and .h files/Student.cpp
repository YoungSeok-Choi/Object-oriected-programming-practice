#include "Student.h"

/*
실습#7
함수 정의
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
/* 위의 2개 함수 실습#9에서 삭제 */

/* publics */
void Student::InPutData()
{
	int i;
	string tmp;
	int hak, sub;

	Student::stnum++;

	cout << "\n* " << Student::stnum << " 번째 학생 이름과 과목수를 입력하세요.\n";
	cout << "이름 : ";
	IOInterface::InPutValue(tmp);
	_Name = tmp;

	cout << "학번 : ";
	IOInterface::InPutValue(hak);
	_Hakbun = hak;

	cout << "과목수 : ";
	IOInterface::InPutValue(sub);
	_SubNum = sub;
	_Sub = new Subject[sub];
	cin.ignore();

	cout << "\n* 수강한 과목 " << _SubNum << "개의 각 교과목명, 과목등급을 입력하세요.\n";
	for (i = 0; i < Student::_SubNum; i++)
		_Sub[i].InPutData();

	_AveGPA = CalcAveGPA();
}

void Student::PrintData() const
{
	int i;

	cout << "====================================================\n";
	cout << "이름 : " << _Name << "  학번 : " << _Hakbun;
	cout << "\n====================================================\n";
	cout << "과목명     과목학점     과목등급     과목평점\n";
	cout << "====================================================\n";

	cout.precision(2);
	cout << fixed;

	for (i = 0; i < _SubNum; i++)
	{
		_Sub[i].PrintData();
		cout << "\n";
	}


	cout << "====================================================\n";
	cout << "\t\t\t\t 평균평점 : " << _AveGPA;
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
실습#8
함수 정의
*/

/* publics */
Student::Student()
{
	_Name = "홍길동";
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
	cout << "\n수정(학생정보/과목정보): ";
	string type;
	IOInterface::InPutValue(type);

	if (type == "학생정보")
	{
		cout << "\n* (" << _Name << ", " << _Hakbun << ")의 정보를 수정하세요\n";
		cout << "이름 : ";
		IOInterface::InPutValue(_Name);
		cout << "\n";
		cout << "학번 : ";
		IOInterface::InPutValue(_Hakbun);
		cout << "\n\n";
	}
	else if (type == "과목정보")
	{
		Subject* temp = NULL;
		temp = SubSearch();

		if (temp == NULL)
		{
			cout << "해당 과목이 존재하지 않습니다. 다시 검색하여 주십시오\n";
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
		cout << "\n올바른 메뉴를 입력하세요\n";
		return;
	}
	return;
}

string Student::GetName()
{
	return _Name;
}
/*위의 함수 실습#10 에서 재정의*/

Subject* Student::SubSearch()
{
	int i;
	string tempsub, comp;
	cout << "검색 할 과목 이름 : ";
	IOInterface::InPutValue(tempsub);

	for (i = 0; i < _SubNum; i++)
	{
		comp = _Sub[i].GetName();
		if (comp == tempsub)
			return &_Sub[i];
	}
	return NULL;
}