#include <iostream>

using namespace std;

// ������
// ��Ģ����
// + - * / % => �ڷ������� �ٸ� �� �ִ�.

// ������
// + - *...
// / ... ���� ��ȯ
// 10 / 3 => 3

// % ... �������� ��ȯ => ��ȯ ����, ������ ���� ���� ��
// 10 % 3 => 1

// �Ǽ���
// + - *
// / ... �ε��Ҽ����� ������ ����

// = ���Կ�����
// a = b : a���ٰ� b�� �����ϰ� a�� ������ ��ȯ�Ѵ�.
// += , -=, *=, /=

// ����������
// ++, --
// aInt++ / aInt-- ... ����������
// aInt = bInt++;
// => aInt���� bInt�� ���� �����ϰ� bInt�� 1�ø���.
// 
// ++aInt / --aInt ... ����������
// aInt = ++bInt;
// => aInt���� �켱 bInt�� 1�ø��� �װ��� �����Ѵ�.

// �񱳿�����
// ��ȯ�ڷ����� bool
// ==, !=, <, >, <=, >=
// == : ������ true �ٸ��� false
// != : �ٸ��� true ������ false !(==)
// a > b...

// ��������
// ��ȯ�ڷ����� bool
// !, &&, ||
// ! : not
// a && b : a�� true�̰� b�� true�� true�� ��ȯ �װԾƴϸ� false
// a || b : a,b �� �߿� �ϳ��� true�� true �װ� �ƴϸ� false

// ��Ʈ������ : ��ȣ���� �������� ���δ�.
// &, |, ^, >>, <<
// a & b : ��Ʈ�� ���ڸ��� �� and
// ex) 1 & 3 : 1
// a | b : ��Ʈ�� ���ڸ��� �� or
// a ^ b : xor ����... ��Ʈ�� ���� ���� ���� �� 1, ������ 0

// << : ���� Shift����
// - *2�� �ȴ�.
// - �����ʺ�Ʈ�� �׻� 0���� ä������.

// >> : ������ Shift����
// - �� ������ ��Ʈ�� �������� �ȴ�.
// - ��ȣ�� �ִ� �������̶�� ���� ��ȣ��Ʈ�� �����ȴ�.

// ��Ʈ�÷���
// [����][����][���][����]
unsigned char state = 0;
unsigned char sturn = 0b1000; // 1 << 3
unsigned char sleep = (1 << 2);
unsigned char airbone = 2;
unsigned char invinsible = 1;

// ��Ʈ����ũ
// & (������� ��Ʈ)

int main()
{
#pragma region ������
	int aInt = 10;
	int bInt = 3;
	int cInt = 0;

	cInt = (aInt + bInt) % bInt;
	cout << cInt << endl;

	float aFloat = 0.0f;
	float cFloat = 10.0f / aFloat;
	cout << cFloat << endl;

	aInt += 1; // aInt = aInt + 1

	cout << ++aInt << endl; // 12
	cout << aInt++ << endl; // 12
	cout << aInt << endl; // 13

	aInt = ++bInt;
	aInt = bInt++;
	cout << aInt << endl; // aInt:4 , bInt 5
	cout << (aInt > bInt) << endl; // false 0
	cout << ((aInt < bInt) > (aInt == bInt)) << endl; // true

	aInt = 2;
	bInt = 3;
	cInt = ++bInt;

	bool check1 = (aInt > bInt);
	bool check2 = (cInt != aInt);
	bool check3 = !check1;

	bool check4 = check3 || check2;
	bool check5 = check2 && (check3 || check4);

	cout << (1 & 2) << endl;
	cout << (1 | 3) << endl;
	// xor...
	// a ^ b ^ b = a... ��ȣ��
	aInt = 1;
	bInt = 3;
	cInt = (aInt ^ bInt);
	cout << (cInt ^ bInt) << endl;

	unsigned char u_aChar = 3;
	unsigned char u_bChar = (1 << 4);
	unsigned char u_cChar = (u_aChar | u_bChar);
	unsigned char u_dChar = (1 << 3) | (1 << 2);
	unsigned char u_fChar = (u_cChar & u_dChar);
#pragma endregion

#pragma region ��Ʈ�÷���
	state |= (sturn | sleep);
	if (state & sturn)
	{
		cout << "���ϻ����Դϴ�." << endl;
	}

	if (state & sleep)
	{
		cout << "���� " << endl;
	}

	if (state & (sleep | sturn))
	{
		cout << "���� ����" << endl;
	}

#pragma endregion

	return 0;
}