#include "pch.h"

// ��缭1
// 1. 1~3�� ���� �Է¹޾Ƽ� Knight, Archer, Mage �� ���� �� �ϳ��� ������ ����(�����Ҵ�)�ϰ� ���ּ���.
// 2. ��ǻ�͵� ������ �޾Ƽ� 1.�� ���� �������ּ���.
// 3. �÷��̾��� �̸��� �Է¹ް� Set���ּ���. ��ǻ�ʹ� ��ǻ�ͷ�
// 4. ������ �� ������ �̸��� ǥ�õǰ����ּ���. ��) Hanil�� ��ǻ�͸� �����߽��ϴ�.
// 5. Knight�� ü���� 50���� �̸��� �Ǹ� ���ݷ��� 2�� �������ϴ�.
// 6. Mage�� ������ 5��ŭ �Һ��Ͽ� ������ �մϴ�. ������ �� ������ �����ϴٸ� 50��ŭ ȸ���ϰ� ������ ���ϴ�.
// 7. Archer 30���� Ȯ���� ũ��Ƽ�� ������(3�� ����)�� �մϴ�.
// 8. �� �� ���� �̱���� üũ�ϰ� �̱� �� ���� �ݺ�

// ��缭2
// 0. ��ǻ�Ϳ� �������� ������� ����ġ�� ������ 1,2 �Է����� ����(��ǻ�Ϳ� ���� �й�� Ȥ�� ����� ���� ��)
// 1. Creature ��ӹ޴� Player ����ϴ�.
// 2. ��缭1�� Knight�� Archer, Mage�� Player�� ��ӹ޽��ϴ�. �� �� Player�� �߻�Ŭ�����Դϴ�.
// 3. Player�� �Ӽ����� ����ġ�� �߰��˴ϴ�.
// 4. Player�� ��� 10������ �ο�� �������� ����ġ�� ��� ����ġ�� ���� ������ �ö󰩴ϴ�.
// 5. ������ ������ ��缭1�� ������ �ٽ��ؼ� �̱�� ���α׷� ����


void SetG_Arr(Goblin arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int randHp = rand() % 21 + 30;
		int randAtk = rand() % 4 + 2;
		arr[i].SetStat(randHp, 0, randAtk);
	}
}

bool GArr_Dead(Goblin arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!arr[i].IsDead()) // ����ִ�
			return false;
	}

	// �� ����
	return true;
}

int main()
{
#pragma region �ǽ�1(�����Ҵ�)
	// 1. Player�� ��ӹ޴� 3���� Ŭ������ ���弼��
	// 2. main�� �� �� 2���� ��ü�� ����ð�(�����Ҵ�, �ڷ����� Creature*)
	// 3. ��ü���� �ο��� �մϴ�. (Attack�� �����Լ��� ����)
	// 4. �̸� �Ѹ��� ���� ������ �ݺ�
	//Creature creature;
	
//	Creature* knight = new Knight(50,0,10,5);
//	Creature* goblin = new Goblin(25, 0, 5);
//
//	knight->Attack(goblin);
//	goblin->Attack(knight);
//
//	delete goblin;
//	delete knight;
//#pragma endregion
//	Creature* goblin_G[10] = { nullptr };
//
//	for (int i = 0; i < 10; i++)
//	{
//		goblin_G[i] = new Goblin(50, 0, 5);
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		delete goblin_G[i];
//	}


// �̸� �Է� �޴�
	string name;
	cin >> name;

	Creature* knight = new Knight(500, 2, 15, 0);
	knight->SetName(name);

	knight->PrintCreature();

	delete knight;

	return 0;
}