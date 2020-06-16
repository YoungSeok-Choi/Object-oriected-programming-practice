#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Students
{
	vector<string> Names;
	vector<int> Hakbuns;
};


/*�ǽ�����#11 �����Լ�*/
inline void PrintMenu();
inline void InputValue(int&);
inline void InputValue(string&);

/*�ǽ�����#11 �䱸�Լ�*/
void InputData(Students& st);
void PrintData(const Students& st);
void DeleteData(Students& st);

/* �䱸�Լ� �̿� �߰��Լ� */
void Alldata_Delete(Students& st);

int main()
{
	int selected_menu = 0;
	Students St;
	Students& st = St;

	do
	{
		PrintMenu();
		InputValue(selected_menu);

		switch (selected_menu)
		{
			case 1:
			{
				InputData(st);
				break;
			}
			case 2:
			{
				PrintData(st);
				break;
			}
			case 3:
			{
				DeleteData(st);
				break;
			}
			case 4:
			{
				cout << "\n���α׷� ����.\n";
				break;
			}
			default:
			{
				cout << "Concentration!!!!\n";
				break;
			}
			
		}

	} while (selected_menu != 4);

	/*�ܿ� data�� �ִ� ���¿��� ������ ��� �ش� data�� ��� �����ϰ� �����ϱ� ���� ���*/
	if (St.Hakbuns.empty() == 0 && St.Names.empty() == 0)
		Alldata_Delete(st);

	return 0;
}

inline void PrintMenu()
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. �л� ���� ����\n";
	cout << "3. �л� ���� ����\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

inline void InputValue(int& ref)
{
	cin >> ref;
}

inline void InputValue(string& ref)
{
	getline(cin, ref);
	if (ref.empty()) getline(cin, ref);
}

void InputData(Students & st)
{
	int temp;
	string temp1;

	cout << "�̸� : ";
	InputValue(temp1);
	st.Names.push_back(temp1);
	cout << "�й� : ";
	InputValue(temp);
	st.Hakbuns.push_back(temp);
}

void PrintData(const Students& st)
{
	int i;

	cout.setf(ios::right);
	cout << "\n";
	cout << setw(20) << "�л� ���� ����";
	cout << "\n========================================\n";
	cout << setw(10) << "�̸�" << "\t" << setw(10) << "�й�\n";
	cout << "========================================\n";

	for (i = 0;i < st.Hakbuns.size();i++)
		cout << setw(10) << st.Names[i] << "\t" << setw(10) << st.Hakbuns[i] << "\n";

	cout << "========================================\n\n";
}

void DeleteData(Students& st)
{
	st.Names.pop_back();
	st.Hakbuns.pop_back();
}

/*���� �߰� �Լ�*/
void Alldata_Delete(Students& st)
{
	int i;
	for (i = 0; i < st.Hakbuns.size(); i++)
	{
		st.Names.pop_back();
		st.Hakbuns.pop_back();
	}
}
