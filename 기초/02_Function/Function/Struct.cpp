#include <iostream>

using namespace std;

// ����� ���� �ڷ���
// ����ü
// 1. ���� �ڷ����� ���� ����� ���ؼ�
// 2. �ڷ����� ������ ������ ���� ����� ���ؼ�

// ������
// (����ü ����). : ���������... ����� ������ �� �ְ� ���ش�.
// (����ü ����)-> : �������������... * . ��ģ ��

struct Player
{
	// �Ӽ� attribute, member
	int hp;
	int mp;

	// 1000����Ʈ
};

// ��´��
// �б� ����
void PrintPlayer(Player player) // ����ü�� ũ�⸸ŭ �Ű����� �Ҵ�
{

}

void PrintPlayer(const Player* const player) // 8����Ʈ�� �Ű�����
{
	cout << "�÷��̾� ����" << endl;
	cout << "Hp : " << player->hp << endl;
	cout << "Mp : " << player->mp << endl;
}

// ���ô��
void SetPlayer(Player* const player, int hp, int mp)
{
	cout << "�÷��̾� ����" << endl;
	(*player).hp = hp;
	player->mp = mp;
}

int main()
{
	Player p;
	p.hp = 0;
	p.mp = 0;

	SetPlayer(&p, 100, 100);
	PrintPlayer(p);

	return 0;
}