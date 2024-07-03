#include "pch.h"
#include "Block.h"

Block::Block()
: RectCollider(Vector2(),Vector2(5,5))
{
	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(RED));
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

	SelectObject(hdc, _brushes[static_cast<int>(_type)]);
	RectCollider::Render(hdc);
	
}

void Block::SetPosition(Vector2 pos)
{
	_center = pos;

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

