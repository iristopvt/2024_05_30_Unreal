#include <iostream>

using namespace std;

// PetŬ������ �߰��ǰ� Player�� ���� �Ѹ��� �����ִ�.
class Pet
{
private:
	int arr[100];
};

class Player
{
public:
	Player()
	:  // �����ʱ�ȭ ����
	_maxHp(150)
	,_hp(0)
	, _hpRef(_hp)
	, _target(nullptr)
	{
		_hp = _maxHp;
		_pet = new Pet();
		cout << "�⺻������ ȣ��" << endl;
	}

	// �⺻������, Ÿ�Ժ�ȯ������
	Player(int hp) // Ÿ�Ժ�ȯ ������
	:_maxHp(hp)
	, _hp(0)
	, _hpRef(_hp)
	, _target(nullptr)
	{
		_hp = _maxHp;
		_pet = new Pet();
		cout << "Ÿ�Ժ�ȯ ������ ȣ��" << endl;
	}

	// ���������
	// �Ϲ������� ������ִ� ������ => ���� ��������� ����� �ȸ������ ...Shallow Copy ���� ����
	// �Ϲ������� ������� �� ��� ��������� �����Ѵ�.
	Player(const Player& other)
	: _maxHp(other._maxHp)
	, _hp(other._hp)
	, _hpRef(other._hpRef)
	, _target(other._target)
	, _pet(nullptr)
	{
		_pet = new Pet(*other._pet); // DeepCopy... ���� ����
		cout << "��������� ȣ��" << endl;
	}

	~Player() 
	{
		delete _pet;
	}

	void SetTarget(Player* other) { _target = other; }
	void Attack()
	{
		cout << "����" << endl;
		//_target->_hp -= 10;
		cout << _target->_hp << endl;
	}

private:
	// �⺻�ڷ���
	int _hp;

	const int _maxHp;
	int& _hpRef;
	Player* _target;
	Pet* _pet; // 4����Ʈ
};

int main()
{
	Player a = Player(); // �⺻������ ȣ��
	Player b = Player(5); // Ÿ�Ժ�ȯ������ ȣ��
	Player c = 2; // Ÿ�Ժ�ȯ������ ȣ��
	Player d = Player(c); // ��������� ȣ��

	Player* a_player = new Player();
	Player* b_player = new Player(*a_player);


	delete a_player;
	delete b_player;

	return 0;
}