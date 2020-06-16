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


/*실습과제#11 제공함수*/
inline void PrintMenu();
inline void InputValue(int&);
inline void InputValue(string&);

/*실습과제#11 요구함수*/
void InputData(Students& st);
void PrintData(const Students& st);
void DeleteData(Students& st);

/* 요구함수 이외 추가함수 */
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
				cout << "\n프로그램 종료.\n";
				break;
			}
			default:
			{
				cout << "Concentration!!!!\n";
				break;
			}
			
		}

	} while (selected_menu != 4);

	/*잔여 data가 있는 상태에서 종료할 경우 해당 data를 모두 삭제하고 종료하기 위한 사용*/
	if (St.Hakbuns.empty() == 0 && St.Names.empty() == 0)
		Alldata_Delete(st);

	return 0;
}

inline void PrintMenu()
{
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 정보 입력\n";
	cout << "2. 학생 정보 보기\n";
	cout << "3. 학생 정보 삭제\n";
	cout << "4. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : ";
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

	cout << "이름 : ";
	InputValue(temp1);
	st.Names.push_back(temp1);
	cout << "학번 : ";
	InputValue(temp);
	st.Hakbuns.push_back(temp);
}

void PrintData(const Students& st)
{
	int i;

	cout.setf(ios::right);
	cout << "\n";
	cout << setw(20) << "학생 정보 보기";
	cout << "\n========================================\n";
	cout << setw(10) << "이름" << "\t" << setw(10) << "학번\n";
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

/*개별 추가 함수*/
void Alldata_Delete(Students& st)
{
	int i;
	for (i = 0; i < st.Hakbuns.size(); i++)
	{
		st.Names.pop_back();
		st.Hakbuns.pop_back();
	}
}
