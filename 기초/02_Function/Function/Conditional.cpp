#include <iostream>

using namespace std;

// ���ǹ�
// if��
// if(������(true / false))
// {
//		���๮
// }
// else if(������)
// {
//		���๮
// }
// else
// {
//		���๮
// }

// switch ��
// switch(���� ������ ����)
// {
//		case 1: { ���๮ break; }
//		case 2: { ���๮ break; }
//      case ...:
// 
//		default:
//      {
//		}
// }

// �ݺ���
// while
// while(������)
// {
//		if��(�����)
//			continue; ���๮�� ����Ǳ� ���� ���� ���� Ÿ�ּ���.
//		���๮
//		�����
//		break;
// }
// 
// for��
// for(�ʱ��; ���ǽ�; �����)
// {
//		continue;
//		���๮
//		break;
// }

int main()
{
	int aInt = 3;
	int bInt = 3;

#pragma region ���ǹ�
	if (aInt > bInt)
	{
		cout << "aInt�� bInt���� Ů�ϴ�." << endl;
	}
	else if (aInt == bInt)
	{
		cout << "aInt�� bInt�� �����մϴ�." << endl;
	}
	else
	{
		cout << "aInt�� bInt���� �۰ų� �����ϴ�." << endl;
	}

	// ������ (�ڷ���)
	enum Test
	{
		ONE = 1,
		TWO,
		THREE
	};

	Test aTest = ONE;

	switch (aTest)
	{
	case ONE:
		break;
	case TWO:
		break;
	case THREE:
		break;
	default:
		break;
	}

	switch (aInt)
	{
	case 1:
	{
		cout << "aInt�� 1�Դϴ�." << endl;
		break;
	}
	case 3:
	{
		cout << "aInt�� 3�Դϴ�." << endl;
		break;
	}

	default:
	{
		cout << "aInt�� ���� �߸𸣰ڽ��ϴ�." << endl;
		break;
	}
	}

#pragma endregion

#pragma region �ݺ���

	aInt = 0;
	while (true)
	{
		if (aInt == 3)
		{
			aInt++;
			continue;
		}

		cout << "�ݺ�!" << aInt << endl;

		aInt++; // �����
		if (aInt == 5)
			break;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 3) continue;
		cout << i << "�� �ݺ�!" << endl;
		if (i == 5) break;
	}

#pragma endregion

	// �ǽ�
	int input = 0;
	cin >> input;

	cout << input << endl;

	// �ǽ� 1
	// 5 �Է��ϸ�
	// *
	// *
	// *
	// *
	// *


	// �ǽ� 2�� ���簢�� �����
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



	// ��ǻ�Ͱ� ������ �����ϴ� ���
	srand(time(NULL));

	// 1 ~ 3
	// 0 ~ 2 + 1
	int randNum = (rand() % 3) + 1; // 
	cout << randNum << endl;


	return 0;
}