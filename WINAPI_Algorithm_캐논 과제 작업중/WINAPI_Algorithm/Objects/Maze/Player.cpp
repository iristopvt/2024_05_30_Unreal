#include "pch.h"
#include "Player.h"

#include "Maze.h"
#include "Block.h"

Player::Player(shared_ptr<Maze> maze)
{
	_maze = maze;
}

Player::~Player()
{
	_maze = nullptr;
}

void Player::BeginPlay()
{
	_maze->SetPlayerPos(_pos); 
	RightHand();
}

void Player::RightHand()
{
	// �ǽ� ? 
	// ������� �̿��ؼ� �̷θ� �������� ���� �ȴ�,
	// ã�� ���� _path���� �ִ´�
	enum Direction
	{
		UP,
		LEFT,
		BOTTOM,
		RIGHT,

		DIR_COUNT = 4
	};

	Vector2 pos = _pos;
	_path.push_back(pos);
	Vector2 endPos = Vector2(23, 23);

	Direction dir = Direction::BOTTOM;

	Vector2 frontpos[4] =
	{
		Vector2{0,-1}, // UP
		Vector2{-1,0},//  LEFT
		Vector2{0,1}, // BOTTOM
		Vector2{1,0}, // RIGHT

	};

	while (true)
	{
		if (pos == endPos)
			break;

		// % �˰��򿡼� ��ȯ�������� ���� ���δ�.
		int newDir = (dir - 1 + DIR_COUNT) % DIR_COUNT;
		Vector2 oldDirVector2 = frontpos[dir];
		Vector2 newDirVector2 = frontpos[newDir];

		Vector2 newPos = pos + newDirVector2; // �� ������ ���� 
		Vector2 oldPos = pos + oldDirVector2; // �� �չ���

		// ���������� �� �� ������ ������ �ٲٰ� ���������� ����
		if (cango(newPos._y,newPos._x)) // ������ ���� ������ ������� ȸ���ϴ� �ڵ� 
		{
			dir = static_cast<Direction>(newDir);
			pos += newDirVector2;
			_path.push_back(pos);
		}
		// �������� �����ְ� �������� �� �� ������ ���� �״�� ������ ����
		else if (cango(oldPos._y, oldPos._x))
		{
			pos += oldDirVector2;
			_path.push_back(pos);
		}
		// ������, �� �Ѵ� �������� �� �������� ȸ��
		else
		{
			dir = static_cast<Direction>((dir + 1 + DIR_COUNT) % DIR_COUNT);
		}
		
	}


}

bool Player::cango(int x, int y)
{
	Block::BlockType blockType = _maze->GetBlockType(y, x);
	if (blockType == Block::BlockType::ABLE)
	{
		return true;
	}

	return false;
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		_pathIndex = 0;
		_path.clear();
		
		return;
	}

	_time += 0.1f; // �����̴� �ӵ� 
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			// ������
			_maze->SetPlayerPos(_pos);

		}

		_pathIndex++;

	}
}
