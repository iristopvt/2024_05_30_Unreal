#include <iostream>

using namespace std;

// �����Ϳ���
// *(�����ͺ���) : ����������
// &(����) : �ּҿ�����

// �������� : +1 �ϸ�... �ڷ����� ũ�⸸ŭ ��������.

// �����迭
// int arr[���] = {�ʱ�ȭ};

// ���� �߿��� Ư��1 : �޸𸮿� �Ϸķ� �����̵Ǿ��ִ�.
// 	int arr[5] = { 1,2,3,4,5 };

// 2 : �迭�� �̸��� ������ó�� �����Ѵ�.

// ���������ϴµ� ����� �ð��� �ɸ���.

// ������
// [����] : �������ٿ�����... ������ ° �ε���(index)�� ����

// Ž�� : �ε��� 
// ��ȸ : for

void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	//            0x10
	int arr[5] = { 3,2,1,4,5 };

	int* ptr = &arr[0]; // 0x10
	cout << *(ptr + 1) << endl; // 0x14
	cout << arr[1] << endl;

	cout << sizeof(arr) << endl;
	int size = sizeof(arr) / sizeof(int);
	cout << "Count : " << size << endl;

	PrintArr(arr, size);

	return 0;
}