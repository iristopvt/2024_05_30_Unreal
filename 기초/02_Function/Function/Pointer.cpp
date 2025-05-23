#include <iostream>

using namespace std;

// ������ ... Pointer
// ����Ű�� ��
// �ּҸ� ����ִ� ����
// (�ڷ���)* (�����ͺ����̸�) = (�ʱ�ȭ);
// (�ڷ���) : ��Ż�� Ÿ�� ���� �� �ش� �ڷ����� ���� ���̴� ��� ��Ʈ

// ũ�� : 32��Ʈ �ü�� ���α׷����� 4����Ʈ, 64��Ʈ �ü�� ���α׷������� 8����Ʈ

// ������
// &(�����̸�) : �ּҿ�����
// *(�����ͺ���) : ����������... ��Ż������

// void* : Ÿ����� ���� �ڷ����� �ִ� �������.

// �Ű������� �� ��
// Call by Value
void AddOne(int num)
{
	num++;
}

// �Ű������� �� '�ּ�'��
// Call by Address
void AddOne(int* ptr)
{
	(*ptr)++; // aInt ... + 1
}


int main()
{
	int aInt = 5;	   // 0x0102FF      5

	int* aPtr = &aInt; // 0x0213FF    0x0102FF 

	cout << "aInt�� �ּ�" << &aInt << endl;
	cout << "aInt ������ ��� �ִ� ��" << aInt << endl;
	cout << "aPtr�� �ּ�" << &aPtr << endl;
	cout << "aPtr ������ ��� �ִ� ��" << aPtr << endl;

	cout << *aPtr << endl; // ����������... ��Ż������
	*aPtr = 6;

	cout << aInt << endl;

	// void*
	void* vPtr = &aInt;
	
	aInt = 0;
	AddOne(&aInt);

	cout << aInt << endl;

	return 0;
}