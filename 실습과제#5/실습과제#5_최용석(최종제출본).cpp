#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 

using namespace std;

typedef struct subject
{
	char subname[30] = { '\0' }; // �ʱ��� gabage value�� ���� �񱳹������� ���� ������ �迭�� ���� ��� 
	int hacjun;
	char grade[10] = { '\0' }; // ���� ����
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

int errorcount = 1; // �л��� data�� �ִ��� ������ �˻��ϴ� flag

// �Լ� ����
// �ǽ� 3 �䱸 �Լ�
void CalcGPA(subject&);
float CalcAveGPA(subject * ptr, int sub); // �䱸���� �߰�
void PrintAllData(const student *sarray, int studentnum); 
void PrintOneData(const student & ref1);
student * StdSearch(student * pSt, int studentnum);
// �ǽ� 4 �䱸�Լ�
void PrintAllStdList(const student * pSt, int studentnum); 
void ModifyStdInfo(student * pSt);
inline void printmenu(void);
inline void InputValue(int & i);
inline void InputValue(char * str);
// �ǽ� 5 �䱸�Լ�
void InputData(student *pSt, int StudentNum);

int main()
{
	student * pSt = NULL;
	student * temp = NULL;
	int command, stunum = 0;
	int subjectnum, i, j;

	do
	{
		printmenu();
		InputValue(command);

		switch (command)
		{
		case 1:
		{
			cout << "\n����� �л����� ���� �Է��Ͻðڽ��ϱ�?\n";
			cout << "�л��� �Է�: ";
			InputValue(stunum);
			pSt = new student[stunum];
			InputData(pSt, stunum);
			continue;
		}
		case 2:
		{
			PrintAllData(pSt, stunum);
			continue;
		}
		case 3:
		{
			temp = StdSearch(pSt, stunum);
			if (temp != NULL) PrintOneData(*temp); // return���� ������ ����ϰ� ������ ���� 
			continue;
		}
		case 4:
		{
			PrintAllStdList(pSt, stunum);
			continue;
		}
		case 5:
		{
			ModifyStdInfo(pSt);
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
	} while (command != 6);
	return 0;
}

// �ǽ� 3 �䱸�Լ�
void CalcGPA(subject & ref1)
{
	string gde[20] = { "A+", "a+", "A0", "a0", "B+",
					 "b+", "B0", "b0", "C+", "c+",
				   "C0", "c0", "D+", "d+","D0",
				  "d0", "F","f" };

		if (gde[0].compare(ref1.grade) == 0 || gde[1].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 4.5;

		else if (gde[2].compare(ref1.grade) == 0 || gde[3].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 4.0;

		else if (gde[4].compare(ref1.grade) == 0 || gde[5].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 3.5;

		else if (gde[6].compare(ref1.grade) == 0 || gde[7].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 3.0;

		else if (gde[8].compare(ref1.grade) == 0 || gde[9].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 2.5;

		else if (gde[10].compare(ref1.grade) == 0 || gde[11].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 2.0;

		else if (gde[12].compare(ref1.grade) == 0 || gde[13].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 1.5;

		else if (gde[14].compare(ref1.grade) == 0 || gde[15].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 1.0;

		else if (gde[16].compare(ref1.grade) == 0 || gde[17].compare(ref1.grade) == 0)
			ref1.gpa = ref1.hacjun * 0.0;

		else
		{
			cout << "������ �ƴ� ������ �Է��Ͽ����Ƿ� ���α׷��� �����մϴ�. �ٽ� �����Ͽ� �ùٸ����� �־��ּ���\n";
			exit(1);
		}
}

float CalcAveGPA(subject * ptr, int sub)
{
	int i;
	float sum = 0.0;
	for (i = 0; i < sub; i++)
		sum += ptr[i].gpa;

	return sum / sub;
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
		cout << "�̸� :  " << sarray[i].stdname << "   �й� : " << sarray[i].hakbun;
		cout << "\n=========================================================================================\n";
		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "\n�����\t\t\t��������\t������\t��������\n";
		cout << "\n=========================================================================================\n";
		for (j = 0; j < sarray[i].subnum; j++)
		{
			cout.width(10);
			cout.precision(2);
			cout << fixed;
			cout << sarray[i].sub[j].subname << "\t\t" << sarray[i].sub[j].hacjun << "\t\t" << sarray[i].sub[j].grade << "\t\t" << sarray[i].sub[j].gpa;
			cout << "\n";
		}

		cout.width(10);
		cout.precision(2);
		cout << fixed;
		cout << "=========================================================================================\n";
		cout << "\t\t\t\t\t�������\t" << sarray[i].aveGPA << "\n\n";
	}
}

void PrintOneData(const student & ref1)
{
	int i;

	cout << "\n�̸� : " << ref1.stdname << "  �й� : " << ref1.hakbun;
	cout << "\n==================================================\n";
	cout.width(10);
	cout << " �����      ��������      ������             �������� \n";
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
	cout << "\t\t\t\t\t������� : " << ref1.aveGPA;
	cout << "\n\n\n";
}

student * StdSearch(student * pSt, int studentnum)
{
	int i;
	string str;												 // �˻��� ���� ����

	cout << "�˻� �� �л� �̸� : ";
	cin >> str;

	for (i = 0; i < studentnum; i++)
	{
		if (str.compare(pSt[i].stdname) == 0) // ���� string�� , i��° �л�����ü�� �̸��� ���ٸ� �ش� ����ü�� �ּҸ� ��ȯ
			return &pSt[i];
		else
			continue;
	}															 // �̸��� ��������� ó��
	cout << "\n�ش��ϴ� �̸��� �л��� �������� �ʽ��ϴ�\n";
	return NULL;
}

// �ǽ� 4 �䱸�Լ�
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

void PrintAllStdList(const student *pSt, int studentnum)
{
	int i;
	cout << "-------------------------------------------\n";
	cout << "�й�         �̸�\n";
	cout << "-------------------------------------------\n";
	for (i = 0; i < studentnum; i++)
	{
		cout.width(5);
		cout << pSt[i].hakbun;
		cout.width(10);
		cout << pSt[i].stdname;
		cout << "\n";
	}
	cout << "-------------------------------------------\n\n\n\n";
}

void ModifyStdInfo(student* pSt)
{
	student * ptr = NULL;
	ptr = StdSearch(pSt, pSt->subnum);
	if (ptr == NULL)   // �˻��Լ����� �޾Ƶ��� �ּҰ��� ���� ������ �ʱⰪ�� ������ �ִ� ��쿡 ���� ����ó��
	{
		cout << "�ٽ� �˻��Ͽ� �ֽʽÿ�\n";
		return;
	}
	else
	{    // �̸��� �й��� ���� ����
		cout << "*<" << ptr->stdname << "," << ptr->hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(ptr->stdname);
		cout << "\n";
		cout << "�й� : ";
		InputValue(ptr->hakbun);
		cout << "\n\n";
	}
}

// �ǽ� 5 �䱸�Լ�
void InputData(student *pSt, int StudentNum)
{
	int i, j;
	/*
			  �л��� ũ�⸸ŭ �����Ҵ� �ް� ������� �޾Ƶ���
	*/

	for (i = 0; i < StudentNum; i++)  //  �л��� ��ŭ ������ ���� �޸� �Ҵ�
	{

		cout << "\n*" << i + 1 << "��° �л��� ������ ��� �����Ͻðڽ��ϱ�? :";
		InputValue(pSt[i].subnum);
		//subjectnum = pSt[i].subnum; // �־ �ǰ� ��� ��

		pSt[i].sub = new subject[pSt[i].subnum];

		cout << "\n*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���\n";
		cout << "�̸� : ";
		InputValue(pSt[i].stdname);
		cout << "�й� : ";
		InputValue(pSt[i].hakbun);
		cout << "\n\n\n\n* ������ ���� " << pSt[i].subnum << "���� �� �������, ��������,  �������� �Է��ϼ���.\n";

		for (j = 0; j < pSt[i].subnum; j++) // ������ �л� ������ ���� �ݺ������� �Է¹��� ���� ũ�⸸ŭ �������� �� ����
		{
			cout << "������� : ";
			InputValue(pSt[i].sub[j].subname);
			cout << "���������� (�ݵ�� ���ڸ� �Է����ּ���!!): ";
			InputValue(pSt[i].sub[j].hacjun);
			cout << "������ < A+ ~ F > : "; // �ҹ��ڵ� ������ �ֵ��� ����
			InputValue(pSt[i].sub[j].grade);
			cout << "\n";
			subject & ref1 = pSt[i].sub[j];
			CalcGPA(ref1); // 1�� ������ ��հ� ���
		}
		pSt[i].aveGPA = CalcAveGPA(pSt[i].sub, pSt[i].subnum); // �л� �Ѹ��� ��ü����ó��
	}

	if (pSt == NULL) // ���� ������ �Ͼ�� �ּҰ� �ٲ����ʴ°Ϳ� ���� ����ó��
	{
		cout << "���� �����Ͱ� ������ �ʱ�ȭ���� �ʾҽ��ϴ�. ";
		return;
	}
	errorcount *= -1;   // flag ������ �ٲ������μ� ���� ���µ� ��������Ϸ��� ��츦 ����
}