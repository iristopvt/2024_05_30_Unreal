#pragma once
class World
{
public:
	enum PlayerType
	{
		NONE = 0,
		KNIGHT = 1,
		ARCHER = 2,
		MAGE = 3
	};

	World();
	~World();
	// �������� : ���������, ������Կ����� �Ѵ�
	// ���������
	// World(const World& other);
	// ���� ���Կ�����
	// World& operator=(const World& other);

	void Init(); // �ʱ�ȭ

	bool End();
	void MultiAttack();
	void Battle1();
	void Battle2(); // ����
	//void MultiAttack();
	vector<Player*> _players;
	void RemovePlayers();

private:
	void SeletPlayer(int num, string name, Player** player);
	void Input();

	Creature* _player;
	Creature* _computer;
	Monster* _hodgoblin;
};

