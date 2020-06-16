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

int errorcount = 1; // �л��� data�� �ִ��� ������ �˻��ϴ� flag


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
				printf("���α׷� ����\n");
				continue;
			}
				
			default:
				printf("�ùٸ� �޴���ȣ�� �Է��ϼ��� \n");
		}
	}while ((i != 4));

	return 0;
}

void printmenu(void) 
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ���α׷� ����\n";
	cout << "\n���ϴ� ����� ��ȣ�� �Է��ϼ��� :";
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
		printf("���� �л������� �����Ͱ� �����ϴ�. ���α׷��� �����մϴ�. \n");
		exit(1);
	}
		
	cout << "\n=========================================================================================\n";
	cout << "��ü �л� ���� ����\n";

	for (i = 0; i < studentnum; i++)
	{
		cout << "\n=========================================================================================\n";
		cout << "�̸� :  " << (sarray+i)->stdname << "   �й� : " << (sarray + i)->hakbun;
		cout << "\n=========================================================================================\n";
		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "\n�����\t\t\t��������\t������\t��������\n";
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
		cout << "\t\t\t\t\t�������\t"<< (sarray + i)->aveGPA <<  "\n\n";
	}
}

void PrintOneData(const student & ref)
{
	int i;

	cout << "\n�̸� : " << ref.stdname << "  �й� : " << ref.hakbun;
	cout << "\n==================================================\n";
	cout.width(10);
	cout << " �����      ��������      ������             �������� \n";
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
	cout << "\t\t\t\t\t������� : "<< ref.aveGPA;
	cout << "\n\n\n";
}

student * StdSearch(student * pSt, int studentnum)
{
	string str;

	cout << "�˻� �� �л� �̸� : ";
	cin >> str;

	if (str == pSt->stdname)
		return pSt;
	else if (str == (pSt + 1)->stdname)
		return (pSt + 1);
	else
	{
		printf("\n�ش��ϴ� �̸��� �л��� �������� �ʽ��ϴ�\n");
		return NULL;
	}
		
}

void entergrade(student array[])
{
	int i = 0;
	int j;

	for (i = 0; i < 2; i++)
	{
		cout << "\n*" << i + 1 << "  ��° �л� �̸��� �й��� �Է��ϼ���\n";
		cout << "�̸� : ";
		cin >> array[i].stdname;
		cout << "�й� : ";
		cin >> array[i].hakbun;
		cout << "\n\n\n\n* ������ ���� 3���� �� �������, ��������,  �������� �Է��ϼ���.\n";
		for (j = 0; j < 3; j++)
		{
			cout << "������� : ";
			cin >> array[i].sub[j].subname;
			cout << "���������� (�ݵ�� ���ڸ� �Է����ּ���!!): ";
			cin >> array[i].sub[j].hacjun;
			cout << "������ <A+ ~ F> (������ �ݵ�� ���ĺ� �빮�ڸ� �Է����ּ���!!) : ";
			cin >> array[i].sub[j].grade;
			cout << "\n";
		}

		cout << "\n\n\n\n";
	}
	errorcount *= -1;
}
