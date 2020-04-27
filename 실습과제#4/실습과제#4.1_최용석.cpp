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
			cout << "5���� ������ �Է��ϼ���: ";
			for (i = 0; i < 5; i++)
				cin >> arr1[i];
			sort<int, int, 5>(arr1); 
			continue;
		}
		case 2:
		{
			cout << "5���� �Ǽ��� �Է��ϼ���: ";
			for (i = 0; i < 5; i++)
				cin >> arr2[i];
			sort<float, float, 5>(arr2);
			continue;
		}
		case 3:
		{
			cout << "���α׷��� �����մϴ�.\n";
			continue;
		}

		default:
			cout << "�ùٸ� �޴���ȣ�� �����ϼ���!\n";
		}
	} while (command != 3);

	return 0;
}


void print_menu()
{

	cout << "1. ���� ����\n";
	cout << "2. �Ǽ� ����\n";
	cout << "3. ����\n";
	cout << "�޴� ����: ";
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

	cout << "\n\n������ �Ϸ�ǰ� �� �� �迭�� ����\n";
	cout.width(3);
	for (i = 0; i < size; i++)
	{
		cout << "  " << arr[i];
	}
	cout << "\n\n";
}
