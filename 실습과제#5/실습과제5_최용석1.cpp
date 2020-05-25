#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 

using namespace std;

typedef struct subject
{
	char subname[30] = { '\0' }; // 초기의 gabage value로 인한 비교문에서의 오류 때문에 배열의 값을 비움 
	int hacjun;
	char grade[10] = { '\0' }; // 위와 동일
	float gpa;
}subject;

typedef struct student
{
	char stdname[30] = { '\0' };
	int hakbun;
	int subnum;
	subject *sub;
	float aveGPA;
}student;

int errorcount = 1; // 학생의 data가 있는지 없는지 검사하는 flag
int stdnum; // 학생수에 대한 전역변수 (함수 이름의 제한으로 어쩔수 없이 전역변수 선언)

inline void printmenu(void);
void CalcGPA(student&);
float CalcAveGPA(subject * ptr);
void PrintAllData(student **sarray, int studentnum); // 원래 const있었음
void PrintOneData(const student & ref1);
student * StdSearch(student ** pSt, int studentnum);
void PrintAllStdList(student ** pSt, int studentnum); // (원래 const 있었음)
void ModifyStdInfo(student ** pSt);  
inline void InputValue(int & i);  
inline void InputValue(char * str);
void InputData(student **pSt, int StudentNum);


int main()
{
	student * rSt = NULL;
	student * temp = NULL;
	int command;

	do
	{
		printmenu();
		cin >> command;

		switch (command)
		{
		case 1:
		{
			cout << "\n몇명의 학생정보 수를 입력하시겠습니까?\n";
			cout << "학생수 입력: ";
			cin >> stdnum;
			InputData(&rSt, stdnum);
			continue;
		}
		case 2:
		{
			PrintAllData(&rSt, stdnum);
			continue;
		}
		case 3:
		{
			temp = StdSearch(&rSt, stdnum);
			if (temp != NULL) PrintOneData(*temp); // return값이 있으면 출력하고 없으면 무시 
			continue;
		}
		case 4:
		{
			PrintAllStdList(&rSt, stdnum);
			continue;
		}
		case 5:
		{
			ModifyStdInfo(&rSt);
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
	exit(1);
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


void CalcGPA(student & ref1)
{
	int j;
	string gde[20] = { "A+", "a+", "A0", "a0", "B+",
					 "b+", "B0", "b0", "C+", "c+",
				   "C0", "c0", "D+", "d+","D0",
				  "d0", "F","f" };

	for (j = 0; j < ref1.subnum; j++)
	{
		subject & rref = ref1.sub[j];

		if (gde[0].compare(rref.grade) == 0 || gde[1].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 4.5;

		else if (gde[2].compare(rref.grade) == 0 || gde[3].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 4.0;

		else if (gde[4].compare(rref.grade) == 0 || gde[5].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 3.5;

		else if (gde[6].compare(rref.grade) == 0 || gde[7].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 3.0;

		else if (gde[8].compare(rref.grade) == 0 || gde[9].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 2.5;

		else if (gde[10].compare(rref.grade) == 0 || gde[11].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 2.0;

		else if (gde[12].compare(rref.grade) == 0 || gde[13].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 1.5;

		else if (gde[14].compare(rref.grade) == 0 || gde[15].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 1.0;

		else if (gde[16].compare(rref.grade) == 0 || gde[17].compare(rref.grade) == 0)
			ref1.sub[j].gpa = ref1.sub[j].hacjun * 0.0;
		else
		{
			cout << "성적이 아닌 정보를 입력하였으므로 프로그램을 종료합니다. 다시 실행하여 올바른값을 넣어주세요\n";
			exit(1);
		}
	}
}


float CalcAveGPA(subject * ptr)
{
	int i;
	float sum = 0;
	for (i = 0; i < 3; i++)
		sum += (ptr + i)->gpa;

	return sum / 3;
}

void PrintAllData(student **sarray, int studentnum)
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
		cout << "이름 :  " << sarray[i]->stdname << "   학번 : " << sarray[i]->hakbun;
		cout << "\n=========================================================================================\n";
		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "\n과목명\t\t\t과목학점\t과목등급\t과목평점\n";
		cout << "\n=========================================================================================\n";
		for (j = 0; j < sarray[i]->subnum; j++)
		{
			cout.width(10);
			cout.precision(2);
			cout << fixed;
			cout << sarray[i]->sub[j].subname << "\t\t" << sarray[i]->sub[j].hacjun << "\t\t" << sarray[i]->sub[j].grade << "\t\t" << sarray[i]->sub[j].gpa;
			cout << "\n";
		}

		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "=========================================================================================\n";
		cout << "\t\t\t\t\t평균평점\t" << sarray[i]->aveGPA << "\n\n";
	}
}

void PrintOneData(const student & ref1)
{
	int i;

	cout << "\n이름 : " << ref1.stdname << "  학번 : " << ref1.hakbun;
	cout << "\n==================================================\n";
	cout.width(10);
	cout << " 과목명      과목학점      과목등급             과목평점 \n";
	cout << "==================================================\n";


	for (i = 0; i < ref1.subnum; i++)
	{
		cout.width(10);
		cout.precision(2);
		cout << fixed;

		cout << ref1.sub[i].subname << "\t" << ref1.sub[i].hacjun << "\t\t" << ref1.sub[i].grade << "\t\t" << ref1.sub[i].gpa;
		cout << "\n";
	}
	cout << "==================================================\n";

	cout.width(10);
	cout.precision(2);
	cout << fixed;
	cout << "\t\t\t\t\t평균평점 : " << ref1.aveGPA;
	cout << "\n\n\n";
}

student * StdSearch(student ** pSt, int studentnum)
{
	int i;
	string str;												 // 검색값 받을 변수

	cout << "검색 할 학생 이름 : ";
	cin >> str;

	for (i = 0; i < studentnum; i++)
	{
		if (str.compare(pSt[i]->stdname) == 0) // 현재 string과 , i번째 학생구조체의 이름이 같다면 해당 구조체의 주소를 반환
			return pSt[i];
		else
			continue;
	}															 // 이름이 없을경우의 처리
		cout << "\n해당하는 이름의 학생은 존재하지 않습니다\n";
		return NULL;
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
	char text[30] = { '\0' };
	cin >> text;
	while (text[i] != '\0')
	{
		*(str + i) = text[i];
		i++;
	}
}

void PrintAllStdList(student **pSt, int studentnum)
{
	int i;
	cout << "-------------------------------------------\n";
	cout << "학번         이름\n";
	cout << "-------------------------------------------\n";
	for (i = 0; i < studentnum; i++)
	{
		cout.width(5);
		cout << pSt[i]->hakbun;
		cout.width(10);
		cout	<< pSt[i]->stdname;
		cout << "\n";
	}
	cout << "-------------------------------------------\n\n\n\n";
}

void ModifyStdInfo(student** pSt)
{
	student * ptr = NULL;
	ptr =	StdSearch(pSt, stdnum);
	if (ptr == NULL)   // 검색함수에서 받아들인 주소값이 없고 여전히 초기값을 가지고 있는 경우에 대한 에러처리
	{
		cout << "다시 검색하여 주십시오\n";
		return;
	}
	else
	{    // 이름과 학번에 대한 변경
		cout << "*<" << ptr->stdname << "," << ptr->hakbun << ">의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(ptr->stdname);
		cout << "\n";
		cout << "학번 : ";
		InputValue(ptr->hakbun);
		cout << "\n\n";
	}
}

void InputData(student **pSt, int StudentNum)
{
	int subjectnum, i, j;
	 pSt[StudentNum] ;  

		 /*
		 학생수 크기의 더블포인터 배열을 선언하고 인덱싱하며 
		 구조체 공간을 힙 영역에서  할당하고,  
		 해당 구조체 안에서 과목수에 대한 구조체 영역을
		 추가적으로 동적 메모리 할당
		 */

    for (i = 0; i < StudentNum; i++)  //  학생수 만큼 루프를 돌며 메모리 할당
			{
				pSt[i] = new student;

				cout << "\n*" << i + 1 << "번째 학생의 과목을 몇개로 지정하시겠습니까? :";
				cin >> pSt[i]->subnum;
				subjectnum = pSt[i]->subnum; 

				pSt[i]->sub = new subject[subjectnum];

				cout << "\n*" << i + 1 << "번째 학생 이름과 학번을 입력하세요\n";
				cout << "이름 : ";
				InputValue(pSt[i]->stdname); 
				cout << "학번 : ";
				InputValue(pSt[i]->hakbun);
				cout << "\n\n\n\n* 수강한 과목 "<<pSt[i]->subnum<< "개와 각 교과목명, 과목학점,  과목등급을 입력하세요.\n";
					
				for (j = 0; j < subjectnum; j++) // 각각의 학생 수마다 위의 반복문에서 입력받은 숫자 크기만큼 루프돌며 값 설정
						{
						cout << "교과목명 : ";
						InputValue(pSt[i]->sub[j].subname);
						cout << "과목학점수 (반드시 숫자를 입력해주세요!!): ";
						InputValue(pSt[i]->sub[j].hacjun);
						cout << "과목등급 < A+ ~ F > : "; // 소문자도 받을수 있도록 개선
						InputValue(pSt[i]->sub[j].grade);
						cout << "\n";
						}
					student & ref1 = *pSt[i];
					CalcGPA(ref1); // 1개 과목의 평균값 계산
					//pSt[i]->aveGPA = CalcAveGPA(pSt[i]->sub[j]); //이거는 픽스가 필요한 문제
			}

	if (pSt == NULL) // 위의 연산이 일어나고도 주소가 바뀌지않는것에 대한 에러처리
	{
		cout << "현재 포인터가 적절히 초기화되지 않았습니다. ";
		return;
	}
	errorcount *= -1;   // flag 변수를 바꿔줌으로서 값이 없는데 성적출력하려는 경우를 방지
}