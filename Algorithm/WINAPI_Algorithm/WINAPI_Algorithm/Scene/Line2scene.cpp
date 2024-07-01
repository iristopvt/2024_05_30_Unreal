#include "pch.h"
#include "Line2scene.h"

Line2scene::Line2scene()
{
	_line1 = make_shared<Line>(Vector2(50, 50), Vector2(50, 50));
	_line2 = make_shared<Line>(Vector2(50, 600), Vector2(800, 50));

	_circle = make_shared<CircleCollider>(Vector2(300, 300), 5);
}

Line2scene::~Line2scene()
{

}

void Line2scene::Update()
{
	_line1->_end = mousePos;

	_line1->Update();
	_line2->Update();
	_circle->Update();


	//if (_line1->IsCollision(_line2))
	//{
	//	_line1->SetRed();
	//}
	//else
	//{
	//	_line1->SetGreen();
	//}
		
	HResult hitResu = _line1->IsCollision(_line2);
	
	if (hitResu.isCollision)
	{
		_line2->SetRed();
		_circle->_center = hitResu.hitPoint;
	}
	else
		_line2->SetGreen();

}

void Line2scene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_circle->Render(hdc);

}
