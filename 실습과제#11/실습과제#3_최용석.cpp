#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 

using namespace std;

typedef struct subject
{
	char subname[30];
	int hacjun ;
	char grade[10];
	float gpa;
}subject;

typedef struct student
{
	char stdname[30];
	int hakbun;
	subject sub[3];
	float aveGPA;
}student;

int errorcount = 1; // 학생의 data가 있는지 없는지 검사하는 flag


void printmenu(void);
void CalcGPA(student&);
float CalcAveGPA(subject * ptr);
void PrintAllData(const student *sarray, int studentnum);
void PrintOneData(const student & ref);
student * StdSearch(student * pSt, int studentnum);
void entergrade(student array[]);


int main()
{
	student * rSt = NULL;
	student st1[2];
	student & ref1 = st1[0];
	student & ref2 = st1[1];
	int i;  
	int StudentNum = 0;

	do
	{
		printmenu();
		cin >> i;

		switch (i)
		{
			case 1:
			{
				entergrade(st1);
				CalcGPA(ref1);
				st1[0].aveGPA = CalcAveGPA(st1[0].sub);
				StudentNum++;
				CalcGPA(ref2);
				st1[1].aveGPA = CalcAveGPA(st1[1].sub);
				StudentNum++;
				continue;
			}
			case 2: 
			{
				PrintAllData(st1, StudentNum);
				continue;
			}
			case 3:
			{
				rSt = StdSearch(st1, StudentNum);
				if(rSt != NULL) PrintOneData(*rSt);
				continue;
			}
			case 4:
			{
				printf("프로그램 종료\n");
				continue;
			}
				
			default:
				printf("올바른 메뉴번호를 입력하세요 \n");
		}
	}while ((i != 4));

	return 0;
}

void printmenu(void) 
{
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 프로그램 종료\n";
	cout << "\n원하는 기능의 번호를 입력하세요 :";
}              

void CalcGPA(student & ref)
{
	int j;
	string gde[10] = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F" };

		for (j = 0; j < 3; j++)
		{
			if (gde[0].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 4.5;

			else if (gde[1].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 4.0;

			else if (gde[2].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 3.5;

			else if (gde[3].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 3.0;

			else if (gde[4].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 2.5;

			else if (gde[5].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 2.0;

			else if (gde[6].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 1.5;

			else if (gde[7].compare(ref.sub[j].grade) == 0)
				ref.sub[j].gpa = ref.sub[j].hacjun * 1.0;

			else
				ref.sub[j].gpa = ref.sub[j].hacjun * 0.0;
		}
	}

float CalcAveGPA(subject * ptr)
{
	int i;
	float sum = 0;
	for (i = 0; i < 3; i++)
		sum += (ptr+i)->gpa;

	return sum / 3.00;
}

void PrintAllData(const student *sarray, int studentnum)
{
	int i, j;

	if (errorcount == 1)
	{
		printf("현재 학생성적의 데이터가 없습니다. 프로그램을 종료합니다. \n");
		exit(1);
	}
		
	cout << "\n=========================================================================================\n";
	cout << "전체 학생 성적 보기\n";

	for (i = 0; i < studentnum; i++)
	{
		cout << "\n=========================================================================================\n";
		cout << "이름 :  " << (sarray+i)->stdname << "   학번 : " << (sarray + i)->hakbun;
		cout << "\n=========================================================================================\n";
		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "\n과목명\t\t\t과목학점\t과목등급\t과목평점\n";
		cout << "\n=========================================================================================\n";
		for (j = 0; j < 3; j++)
		{
			cout.width(10);
			cout.precision(2);
			cout<<fixed;
			cout << (sarray + i)->sub[j].subname <<"\t\t"<< (sarray + i)->sub[j].hacjun <<"\t\t"<< (sarray + i)->sub[j].grade <<"\t\t"<< (sarray + i)->sub[j].gpa;
			cout << "\n";
		}
		
		cout.width(10);
		cout.precision(2);
		cout<<fixed;
		cout << "=========================================================================================\n";
		cout << "\t\t\t\t\t평균평점\t"<< (sarray + i)->aveGPA <<  "\n\n";
	}
}

void PrintOneData(const student & ref)
{
	int i;

	cout << "\n이름 : " << ref.stdname << "  학번 : " << ref.hakbun;
	cout << "\n==================================================\n";
	cout.width(10);
	cout << " 과목명      과목학점      과목등급             과목평점 \n";
	cout << "==================================================\n";
	

	for(i=0;i<3;i++)
	{
		cout.width(10);
		cout.precision(2);
		cout << fixed;

		cout << ref.sub[i].subname << "\t" << ref.sub[i].hacjun << "\t\t" <<ref.sub[i].grade<< "\t\t" << ref.sub[i].gpa;
		cout << "\n";
	}
	cout << "==================================================\n";

	cout.width(10);
	cout.precision(2);
	cout << fixed;
	cout << "\t\t\t\t\t평균평점 : "<< ref.aveGPA;
	cout << "\n\n\n";
}

student * StdSearch(student * pSt, int studentnum)
{
	string str;

	cout << "검색 할 학생 이름 : ";
	cin >> str;

	if (str == pSt->stdname)
		return pSt;
	else if (str == (pSt + 1)->stdname)
		return (pSt + 1);
	else
	{
		printf("\n해당하는 이름의 학생은 존재하지 않습니다\n");
		return NULL;
	}
		
}

void entergrade(student array[])
{
	int i = 0;
	int j;

	for (i = 0; i < 2; i++)
	{
		cout << "\n*" << i + 1 << "  번째 학생 이름과 학번을 입력하세요\n";
		cout << "이름 : ";
		cin >> array[i].stdname;
		cout << "학번 : ";
		cin >> array[i].hakbun;
		cout << "\n\n\n\n* 수강한 과목 3개와 각 교과목명, 과목학점,  과목등급을 입력하세요.\n";
		for (j = 0; j < 3; j++)
		{
			cout << "교과목명 : ";
			cin >> array[i].sub[j].subname;
			cout << "과목학점수 (반드시 숫자를 입력해주세요!!): ";
			cin >> array[i].sub[j].hacjun;
			cout << "과목등급 <A+ ~ F> (과목은 반드시 알파벳 대문자를 입력해주세요!!) : ";
			cin >> array[i].sub[j].grade;
			cout << "\n";
		}

		cout << "\n\n\n\n";
	}
	errorcount *= -1;
}
