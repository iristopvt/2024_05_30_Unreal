#include "pch.h"
#include "Block.h"

Block::Block()
: RectCollider(Vector2(20,20),Vector2(50,15)) // 미로찾기할때는 (5,5)
{
	_brushes.push_back(CreateSolidBrush(WHITE));
	//_brushes.push_back(CreateSolidBrush(RED));
	_brushes.push_back(CreateSolidBrush(WHITE));

	// _pens[]
	_pens.push_back(CreatePen(PS_SOLID, 3, WHITE));
	SetGreen();
}

Block::~Block()
{
	for (auto brush : _brushes)
	{
		DeleteObject(brush);
	}

}

void Block::Update()
{
	RectCollider::Update();

}

void Block::Render(HDC hdc)
{
	//SelectObject(hdc, _pens[static_cast<int>(_type)]);

	//if (_type == BlockType::DISABLE)
	//{
	//	return; // 활성화 체크 
	//}

	if (!_isActive) // 비활성화 상태인 경우 렌더링하지 않음
		return;
	SelectObject(hdc, _brushes[static_cast<int>(_type)]);
	RectCollider::Render(hdc);
	
}

void Block::SetPosition(Vector2 pos)
{
	_center = pos;

}

bool Block::IsActive() const
{
	return _isActive; // 블록의 활성화 상태 반환
}

void Block::SetActive(bool active)
{
	_isActive = active; // 블록의 활성화 상태 설정

}

void Block::SetBlockType(BlockType type)
{
	_type = type;
	_curPen = _pens[static_cast<int>(_type)];

	//switch (type)
	//{
	//case Block::BlockType::ABLE:
	//{
	//	SetGreen();

	//}
	//	break;
	//case Block::BlockType::DISABLE:
	//{
	//	SetRed();

	//}
	//	break;
	//case Block::BlockType::PLAYER_POS:
	//{
	//}
	//	break;
	//
	//default:
	//	break;
	//}
}

