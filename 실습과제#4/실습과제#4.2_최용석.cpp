#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 

using namespace std;

typedef struct subject
{
	char subname[30] = {'\0'}; // 초기의 gabage value로 인한 비교문에서의 오류 때문에 배열의 값을 비움 
	int hacjun;
	char grade[10] = {'\0'}; // 위와 동일
	double gpa;
}subject;

typedef struct student
{
	char stdname[30] = {'\0'};
	int hakbun;
	subject sub[3];
	double aveGPA;
}student;

int errorcount = 1; // 학생의 data가 있는지 없는지 검사하는 flag

inline void printmenu(void);
void CalcGPA(student&);
double CalcAveGPA(subject * ptr);
void PrintAllData(const student *sarray, int studentnum =2);
void PrintOneData(const student & ref);
student * StdSearch(student * pSt, int studentnum = 2);
void PrintAllStdList(const student * pSt, int studentnum = 2); // 지정된 학생수 2명으로 디폴트 인자 선언
void ModifyStdInfo(student * pSt);  // 과제의 요구사항에 따른 학생 정보 수정 함수 선언
inline void InputValue(int & i);   //중복된 인라인 함수 선언부분
inline void InputValue(char * str);


int main()
{
	student * rSt = NULL;
	student st1[2];
	student & ref1 = st1[0];
	student & ref2 = st1[1];
	int command, i, j, stdcount = 0;
	int StudentNum = 0;

	do
	{
		printmenu();
		cin >> command;

		switch (command)
		{
		case 1:
		{
			for (i = 0; i < 2; i++)
			{
				cout << "\n*" << i + 1 << "  번째 학생 이름과 학번을 입력하세요\n";
				cout << "이름 : ";
				InputValue(st1[i].stdname);
				cout << "학번 : ";
				InputValue(st1[i].hakbun);
				cout << "\n\n\n\n* 수강한 과목 3개와 각 교과목명, 과목학점,  과목등급을 입력하세요.\n";
				for (j = 0; j < 3; j++)
				{
					cout << "교과목명 : ";
					InputValue(st1[i].sub[j].subname); 
					cout << "과목학점수 (반드시 숫자를 입력해주세요!!): ";
					InputValue(st1[i].sub[j].hacjun); 
					cout << "과목등급 < A+ ~ F > : "; // 소문자도 받을수 있도록 개선
					InputValue(st1[i].sub[j].grade);
					cout << "\n";
				}
			}
			CalcGPA(ref1);
			st1[0].aveGPA = CalcAveGPA(st1[0].sub);
			CalcGPA(ref2);
			st1[1].aveGPA = CalcAveGPA(st1[1].sub);
			errorcount *= -1; // flag 변수를 바꿔줌으로서 값이 없는데 성적출력하려는 경우를 방지 
			continue;
		}
		case 2:
		{
			PrintAllData(st1);
			continue;
		}
		case 3:
		{
			rSt = StdSearch(st1);
			if (rSt != NULL) PrintOneData(*rSt); // return값이 있으면 출력하고 없으면 무시
			continue;
		}
		case 4:
		{
			PrintAllStdList(st1);
			continue;
		}
		case 5:
		{
			ModifyStdInfo(st1);
			continue;
		}
		case 6:
		{
			printf("프로그램 종료\n");
			continue;
		}
		default:
			printf("올바른 메뉴번호를 입력하세요 \n");

		}
	} while ((command != 6));

	return 0;
}

inline void printmenu(void)
{
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n";
	cout << "\n원하는 기능의 번호를 입력하세요 :";
}

void CalcGPA(student & ref)
{
	int j;
	string gde[20] = {"A+", "a+", "A0", "a0", "B+",
		              "b+", "B0", "b0", "C+", "c+",
				      "C0", "c0", "D+", "d+","D0",
					  "d0", "F","f"};

	for (j = 0; j < 3; j++)
	{	
		
		if (gde[0].compare(ref.sub[j].grade) == 0 || gde[1].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 4.5;

		else if (gde[2].compare(ref.sub[j].grade) == 0 || gde[3].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 4.0;

		else if (gde[4].compare(ref.sub[j].grade) == 0 || gde[5].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 3.5;

		else if (gde[6].compare(ref.sub[j].grade) == 0 || gde[7].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 3.0;

		else if (gde[8].compare(ref.sub[j].grade) == 0 || gde[9].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 2.5;

		else if (gde[10].compare(ref.sub[j].grade) == 0 || gde[11].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 2.0;

		else if (gde[12].compare(ref.sub[j].grade) == 0 || gde[13].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 1.5;

		else if (gde[14].compare(ref.sub[j].grade) == 0 || gde[15].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 1.0;

		else if (gde[16].compare(ref.sub[j].grade) == 0 || gde[17].compare(ref.sub[j].grade) == 0)
			ref.sub[j].gpa = ref.sub[j].hacjun * 0.0;
		else
		{
			cout << "성적이 아닌 정보를 입력하였으므로 프로그램을 종료합니다. 다시 실행하여 올바른값을 넣어주세요\n";
			exit(1);
		}
			
	}
}

double CalcAveGPA(subject * ptr)
{
	int i;
	double sum = 0;
	for (i = 0; i < 3; i++)
		sum += (ptr + i)->gpa;

	return sum / 3.00;
}

void PrintAllData(const student *sarray, int studentnum)
{
	int i, j;

	if (errorcount == 1) // 학생성적의 data가 없는데 해당 기능을 사용하려는 경우 방지 
	{
		printf("현재 학생성적의 데이터가 없습니다. 프로그램을 종료합니다. \n");
		exit(1);
	}

	cout << "\n=========================================================================================\n";
	cout << "전체 학생 성적 보기\n";

	for (i = 0; i < studentnum; i++)
	{
		cout << "\n=========================================================================================\n";
		cout << "이름 :  " << (sarray + i)->stdname << "   학번 : " << (sarray + i)->hakbun;
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
			cout << fixed;
			cout << (sarray + i)->sub[j].subname << "\t\t" << (sarray + i)->sub[j].hacjun << "\t\t" << (sarray + i)->sub[j].grade << "\t\t" << (sarray + i)->sub[j].gpa;
			cout << "\n";
		}

		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "=========================================================================================\n";
		cout << "\t\t\t\t\t평균평점\t" << (sarray + i)->aveGPA << "\n\n";
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


	for (i = 0; i < 3; i++)
	{
		cout.width(10);
		cout.precision(2);
		cout << fixed;

		cout << ref.sub[i].subname << "\t" << ref.sub[i].hacjun << "\t\t" << ref.sub[i].grade << "\t\t" << ref.sub[i].gpa;
		cout << "\n";
	}
	cout << "==================================================\n";

	cout.width(10);
	cout.precision(2);
	cout << fixed;
	cout << "\t\t\t\t\t평균평점 : " << ref.aveGPA;
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

inline void InputValue(int & i)
{
	int temp;
	cin >> temp;
	i = temp;
} 

inline void InputValue(char * str)
{
	int i = 0;
	char text[30] = {'\0'};
	cin >> text;
	while (text[i] != '\0')
	{
		*(str + i) = text[i];
		i++;
	}
}

void PrintAllStdList(const student * pSt, int studentnum )
{
	int i;
	cout << "-------------------------------------------\n";
	cout << " 학번	이름\n";
	cout << "-------------------------------------------\n";
	for (i = 0; i < studentnum; i++)
	{
		cout.width(10);
		cout << pSt->hakbun << "\t" << pSt->stdname;
		cout << "\n";
		pSt++;
	}
	cout << "-------------------------------------------\n\n\n\n";
}

void ModifyStdInfo(student * pSt)
{
	student * ptr = StdSearch(pSt);
	if (ptr == NULL)
	{
		cout << "다시 검색하여 주십시오\n";
		return;
	}
	else
	{
		cout << "*<" << ptr->stdname << "," << ptr->hakbun << ">의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(ptr->stdname);
		cout << "\n";
		cout << "학번 : ";
		InputValue(ptr->hakbun);
		cout << "\n\n";
	}
}