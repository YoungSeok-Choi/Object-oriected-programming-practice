#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 

using namespace std;

typedef struct subject
{
	char subname[30] = {'\0'}; // �ʱ��� gabage value�� ���� �񱳹������� ���� ������ �迭�� ���� ��� 
	int hacjun;
	char grade[10] = {'\0'}; // ���� ����
	double gpa;
}subject;

typedef struct student
{
	char stdname[30] = {'\0'};
	int hakbun;
	subject sub[3];
	double aveGPA;
}student;

int errorcount = 1; // �л��� data�� �ִ��� ������ �˻��ϴ� flag

inline void printmenu(void);
void CalcGPA(student&);
double CalcAveGPA(subject * ptr);
void PrintAllData(const student *sarray, int studentnum =2);
void PrintOneData(const student & ref);
student * StdSearch(student * pSt, int studentnum = 2);
void PrintAllStdList(const student * pSt, int studentnum = 2); // ������ �л��� 2������ ����Ʈ ���� ����
void ModifyStdInfo(student * pSt);  // ������ �䱸���׿� ���� �л� ���� ���� �Լ� ����
inline void InputValue(int & i);   //�ߺ��� �ζ��� �Լ� ����κ�
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
				cout << "\n*" << i + 1 << "  ��° �л� �̸��� �й��� �Է��ϼ���\n";
				cout << "�̸� : ";
				InputValue(st1[i].stdname);
				cout << "�й� : ";
				InputValue(st1[i].hakbun);
				cout << "\n\n\n\n* ������ ���� 3���� �� �������, ��������,  �������� �Է��ϼ���.\n";
				for (j = 0; j < 3; j++)
				{
					cout << "������� : ";
					InputValue(st1[i].sub[j].subname); 
					cout << "���������� (�ݵ�� ���ڸ� �Է����ּ���!!): ";
					InputValue(st1[i].sub[j].hacjun); 
					cout << "������ < A+ ~ F > : "; // �ҹ��ڵ� ������ �ֵ��� ����
					InputValue(st1[i].sub[j].grade);
					cout << "\n";
				}
			}
			CalcGPA(ref1);
			st1[0].aveGPA = CalcAveGPA(st1[0].sub);
			CalcGPA(ref2);
			st1[1].aveGPA = CalcAveGPA(st1[1].sub);
			errorcount *= -1; // flag ������ �ٲ������μ� ���� ���µ� ��������Ϸ��� ��츦 ���� 
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
			if (rSt != NULL) PrintOneData(*rSt); // return���� ������ ����ϰ� ������ ����
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
			printf("���α׷� ����\n");
			continue;
		}
		default:
			printf("�ùٸ� �޴���ȣ�� �Է��ϼ��� \n");

		}
	} while ((command != 6));

	return 0;
}

inline void printmenu(void)
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n";
	cout << "\n���ϴ� ����� ��ȣ�� �Է��ϼ��� :";
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
			cout << "������ �ƴ� ������ �Է��Ͽ����Ƿ� ���α׷��� �����մϴ�. �ٽ� �����Ͽ� �ùٸ����� �־��ּ���\n";
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

	if (errorcount == 1) // �л������� data�� ���µ� �ش� ����� ����Ϸ��� ��� ���� 
	{
		printf("���� �л������� �����Ͱ� �����ϴ�. ���α׷��� �����մϴ�. \n");
		exit(1);
	}

	cout << "\n=========================================================================================\n";
	cout << "��ü �л� ���� ����\n";

	for (i = 0; i < studentnum; i++)
	{
		cout << "\n=========================================================================================\n";
		cout << "�̸� :  " << (sarray + i)->stdname << "   �й� : " << (sarray + i)->hakbun;
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
			cout << fixed;
			cout << (sarray + i)->sub[j].subname << "\t\t" << (sarray + i)->sub[j].hacjun << "\t\t" << (sarray + i)->sub[j].grade << "\t\t" << (sarray + i)->sub[j].gpa;
			cout << "\n";
		}

		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "=========================================================================================\n";
		cout << "\t\t\t\t\t�������\t" << (sarray + i)->aveGPA << "\n\n";
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
	cout << "\t\t\t\t\t������� : " << ref.aveGPA;
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
	cout << " �й�	�̸�\n";
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
		cout << "�ٽ� �˻��Ͽ� �ֽʽÿ�\n";
		return;
	}
	else
	{
		cout << "*<" << ptr->stdname << "," << ptr->hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(ptr->stdname);
		cout << "\n";
		cout << "�й� : ";
		InputValue(ptr->hakbun);
		cout << "\n\n";
	}
}