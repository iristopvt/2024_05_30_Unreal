#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// �̵� (�̻�)
//

class Pet
{
};

class Player
{
public:
	Player() { cout << "�⺻ ������ ȣ��" << endl; _pet = new Pet(); }
	Player(int hp) { cout << "Ÿ�� ��ȯ ������ ȣ��" << endl; _pet = new Pet(); }
	Player(const Player& other) 
	{
		cout << "��������� ȣ��" << endl;

		_pet = new Pet(*other._pet);
	}
	
	// && : ������ ����
	// 1. ������ ����
	// 2. �̻�
	Player(Player&& other) noexcept 
	{ 
		cout << "�̵������� ȣ��" << endl; 
		if (_pet != nullptr)
			delete _pet;

		_pet = other._pet;
		other._pet = nullptr;
	}
	~Player() { cout << "�Ҹ��� ȣ��" << endl; if (_pet != nullptr) delete _pet; }

	Pet* _pet;
};

// Lvalue : ������
// ������ �� �ִ� �� => ��򰡿� ����Ǿ��ִ�.
// ��ǥ������ ����

// Rvalue : ������
// ������ �� ���� ��, ���
// ��ǥ������ ���, const

// 1. Call by Value
// => ������ �ٲ��� �ʴ´�.
// ==> �Լ� ���ο� ������ص� ������.
// �Ű������� ũ��� �ڷ����� ���� �ٸ���.
//void SetPlayer(Player p)
//{
//
//}

// 2. Call by Address
// => ������ �ٲ��.
// �Ű������� ũ��� �������� ũ�⿡ ������.
// ���� : ���� ��ƴ�. �߸����� �޸� ������ ���� �� �ִ�.
void SetPlayer(Player* const p)
{

}

// 3. Call by Reference
// => ������ �ٲ��.
// �Ű������� ũ��� �������� ũ�⿡ ������.
// ���� : ���� ���ϴ�. �޸� ������ ����ų ���ɼ��� ����.
// ���� : ���� �������� �����ް� ������ ���, ���뼺�� ����.
void SetPlayer(Player& p)
{
	
}

// 4. ������ ���� ����
// => ������ ���� ����
// �Ű������� ũ��� �������� ũ�⿡ ������.(X)
// - �̻�(������ �Ѽ��� �� �ִ�.)�� �Ѵ�.
void SetPlayer(Player&& p, Player&& p2)
{
	delete p._pet;
	p._pet = nullptr;
}

int main()
{
	Player* playerB = new Player();
	Player* playerA = new Player(std::move(*playerB));

	unique_ptr<Player> pPtr = make_unique<Player>();
	unique_ptr<Player> pPtr2 = std::move(pPtr);

	delete playerA;
	delete playerB;

	return 0;
}