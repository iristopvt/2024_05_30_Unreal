#include <iostream>

using namespace std;

// �Լ�
// ��ȯ���� �Լ��̸� (�Ű�����)
// {
//		�Լ� ����
// 
//		return (��ȯ��);
// }

// void : ������... ����... �ڷ���

// �Լ� ȣ�� 
// �Լ��̸�(�Ű�����)

// ȣ�⽺��
// ���� : ������ũ ����, ž�ױ�

// �Լ� �����ε� : �Լ��� �̸��� ���Ƶ�, �Ű������� ������ ������Ÿ���� �ٸ��� ���.. ��ȯ���ĵ�
// �޶� ���

// �Լ��� ���� ����
// 1. ���뼺
// 2. �ڵ� ������(�Լ� �̸� �߿�)

void HelloFunc(void)
{
	cout << "Hello Function" << endl;

	return;
}

void PrintNum(int num)
{
	cout << num << endl;

	return;
}

int AddOne(int num)
{
	num++;

	return num;
}

void SumNum(int num1, int num2)
{
	int sum = num1 + num2;

	cout << sum << endl;
	return;
}

// �Լ� �����ε�
void SumNum(int num1, int num2, int num3)
{
	int sum = num1 + num2 + num3;

	cout << sum << endl;
}

// �Լ��� �⺻ ����
void SumNum(int num1, int num2, int num3, int num4, int num5 = 0)
{
	int sum = num1 + num2 + num3 + num4 + num5;

	cout << sum << endl;
}

void Stars(int input)
{
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;
	cout << "Hello World!" << endl;
}

// 3! = 3 x 2 x 1
// ���ȣ���� �ϴ� �Լ�
// ���ÿ����÷ο쿡 ��������
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}

int main(void)
{
	Stars(5);

	int aInt = 1;
	aInt = AddOne(aInt);
	
	cout << Factorial(100000) << endl;

	return 0;
}