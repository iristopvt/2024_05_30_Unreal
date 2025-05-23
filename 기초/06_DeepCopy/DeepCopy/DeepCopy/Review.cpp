#include <iostream>

using namespace std;

// Ŭ����
// - 3�Ӽ�
// -- ���м�
// -- ��Ӽ�
// -- ������

// ���м� : Ŭ�������� ����������(public, private, protected)
// - (private)��������� (public)����Լ�...(�޼ҵ�)
// ��Ӽ� : is - a ���谡 ���� (Cat is a Animal)
// ������
// - �Լ������ε�(�Լ��̸��� ����, �Ű����� �����̳� �ڷ����� �ٸ� ���� ����),
// - �Լ��������̵�(�θ��� �Լ��� �ڽĿ��� ������)

// �����Լ�
// - �����Լ��� ����/�����ϸ� vftable�� ����� ��ĳ�������� �� ���� ������ ��ü �ڷ����� �Լ��� ȣ���� �� �ִ�.

// �����Ҵ�
// [Code]
// [Data]
// - ��������
// - ��������
// �����ֱ� : ���α׷� ���� / ����
// => ���� : ��𼭳� ����ͼ� �� �� �ִ�.
// => ���� : ��𼭳� ����ͼ� �� �� �ִ�./ �޸� ������ ��ų �� ����.
// 
// [Stack]
// - ���������� : [��ȯ�ּҰ�][��������][�Ű�����]
// �����ֱ� : �Լ��� ȣ��Ǿ��� ��/ �Լ��� ����Ǿ��� ��
// => ���� : ���� �������� ���� �ֱ⸦ ������ �� �ִ�.
// => ���� : ������ ���� ���� �����ֱ⸦ ������ �� ����.
// 
// [Heap]
// - ����� ����, ���α׷��� ����, ũ�Ⱑ ���� ŭ
// �����ֱ� : ����� �������
// => ���� : �� ������� �Ҵ��ϰ� ������ �� �ִ�.
// => ���� : �޸� ����

int aInt = 0; // ��������

class Player
{
public:
	Player() : _id(1) {}

	virtual void PrintInfo()
	{
		cout << "Player �Դϴ�." << endl;
	}

	int _id;
};

class Knight : public Player
{
public:
	Knight() : _hp(2) {}

	virtual void PrintInfo() override
	{
		cout << "Knight �Դϴ�." << endl;
	}

	// �������
	int _hp;
};

int Temp(int hp) // hp : �Ű�����, Parameter(Param) / Argument
{
	int mp = 0; // ��������

	return Temp(mp);
}

Knight* Alloc()
{
	Knight* k = new Knight();

	return k;
}

int main()
{
	// �����Ҵ�
	// ��������
	// ��ĳ����
	Player* knight = new Knight();
	knight->PrintInfo();

	Temp(5);

	Knight* temp = Alloc();

	delete temp;

	return 0;
}