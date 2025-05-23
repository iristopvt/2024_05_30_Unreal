#include "pch.h"
#include "Creature.h"
#include "Knight.h"

Knight::Knight()
// ���� �ʱ�ȭ ����
: Creature()
{
	// ���� �ʱ�ȭ ����
	cout << "Knight�� �⺻������" << endl;

	_stamina = 0;
}

Knight::Knight(int hp, int mp, int attack, int stamina)
: Creature(hp, mp, attack)
{
	cout << "Knight�� Ÿ�Ժ�ȯ ������" << endl;
	_stamina = stamina;
}

Knight::~Knight()
{
	cout << "Knight�� �Ҹ���" << endl;
}

// �Լ� �������̵�
void Knight::Attack(Creature* p)
{
	if (IsDead() || p->IsDead()) return;

	cout << "Knight�� Attack!!!" << endl;
	p->TakeDamage(_attack);
}
