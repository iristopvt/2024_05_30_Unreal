#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int atk, int mp)
// : Creature()
	: Creature(name, hp, atk, mp)
	, _exp(0), Aggro(0)
{
}

Player::~Player()
{
}

//void Player::Die()
//{
//	Creature::Die(); // �⺻ �޽��� ���
//	cout << "�÷��̾� " << _name << "��(��) �׾����ϴ�!" << endl;
//}

//void Player::Angnum()
//{
//	if (_Ang > 0  )
//	{
//
//	}
//
//
//}
