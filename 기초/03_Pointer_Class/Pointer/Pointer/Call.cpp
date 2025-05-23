#include <iostream>

using namespace std;

struct Player
{
	int hp;
	int mp;
};

// Call By Value : ���� �����ؼ� �ѱ��.
void PrintPlayer_Value(Player p)
{
	cout << p.hp << endl;
	cout << p.mp << endl;
}

void SetPlayer_Value(Player p, int hp, int mp)
{
	// ���θ��� �Ű����� p
	p.hp = hp;
	p.mp = mp;
}

// Call By Ref : ������ �ѱ��.
void PrintPlayer_Ref(const Player& p) // �б�����
{
	cout << p.hp << endl;
	cout << p.mp << endl;
}

void SetPlayer_Ref(Player& p, int hp, int mp)
{
	p.hp = hp;
	p.mp = mp;
}

// Call By Address : ������ �ѱ��.
void PrintPlayer_Ptr(const Player* const p)
{
	cout << p->hp << endl;
	cout << p->mp << endl;
}

void SetPlayer_Ptr(Player* const p, int hp, int mp)
{
	p->hp = hp;
	p->mp = mp;
}

// Player* p1;
// Player*& p = p1;
void PrintPlayer(Player*& p)
{
	cout << p->hp << endl;
	cout << p->mp << endl;
}

// Ÿ�� ���� Player*
// Player* p1;
// Player** p = &p1;
void PrintPlayer(Player** p)
{
	Player* player = *p;
	cout << player->hp << endl;
	cout << player->mp << endl;
}

int main()
{
	Player p;
	p.hp = 0;
	p.mp = 0;

	SetPlayer_Ptr(&p, 50, 50);
	PrintPlayer_Ptr(&p);

	return 0;
}