#include "pch.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int atk,int mp)
: Creature(name, hp, atk,mp)
{
}

Monster::~Monster()
{
}

void Monster::Attack(Creature* other)
{
	this->Creature::PreAttack(other);
	other->TakeDamage(_atk);

}

//void Monster::MutilAtack(Creature* other)
//{
//	//Player* player;
//	//
//	//for (int i = 1; i < 5; i++)
//	//{
//	//	this->Creature::PreAttack(other);
//	//	if (player->_Ang >= 40) // �̷��� �Ѹ��� ��׷� ��ġ�� �Ǵ��ؼ� 4�������� 
//	//		other->TakeDamage(_atk); // �ѹ� ������ ���� ��븦 �����ؾ��ҵ� 
//	//	else if (player->_Ang >= 35)
//	//		other->TakeDamage(_atk);
//	//	else if (player->_Ang >= 15)
//	//		other->TakeDamage(_atk);
//
//	//	//else if (player->_Ang > 3)//other->
//
//	//}
//
//
//}
