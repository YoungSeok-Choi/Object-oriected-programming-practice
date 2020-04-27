#include <iostream>
#include <iomanip>

using namespace std;

template <typename V, typename V1, int size> void sort(V1 * arr);
void print_menu();


int main()
{
	int i,command,temp = 0, size = 5;
	int arr1[5] = {};
	float arr2[5] = {};


	do
	{
		print_menu();
		cin >> command;

		switch (command)
		{
		case 1:
		{
			cout << "5개의 정수를 입력하세요: ";
			for (i = 0; i < 5; i++)
				cin >> arr1[i];
			sort<int, int, 5>(arr1); 
			continue;
		}
		case 2:
		{
			cout << "5개의 실수를 입력하세요: ";
			for (i = 0; i < 5; i++)
				cin >> arr2[i];
			sort<float, float, 5>(arr2);
			continue;
		}
		case 3:
		{
			cout << "프로그램을 종료합니다.\n";
			continue;
		}

		default:
			cout << "올바른 메뉴번호를 선택하세요!\n";
		}
	} while (command != 3);

	return 0;
}


void print_menu()
{

	cout << "1. 정수 정렬\n";
	cout << "2. 실수 정렬\n";
	cout << "3. 종료\n";
	cout << "메뉴 선택: ";
}


template <typename V, typename V1, int size> void sort(V1 *arr)
{
	int i, j;
	V temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	}

	cout << "\n\n정렬이 완료되고 난 후 배열의 순서\n";
	cout.width(3);
	for (i = 0; i < size; i++)
	{
		cout << "  " << arr[i];
	}
	cout << "\n\n";
}
