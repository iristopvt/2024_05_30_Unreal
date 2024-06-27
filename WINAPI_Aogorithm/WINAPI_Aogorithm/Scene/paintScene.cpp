#include "pch.h"
#include "paintScene.h"

PaintScene::PaintScene()
{
    _rect = make_shared<Rect>(Vector2(0.0f, 0.0f), Vector2(50.0f, 50.0f));

    _circle = make_shared<Circle>(Vector2(50.0f, 50.0f), 50.0f);
}

PaintScene::~PaintScene()
{
    _rect->_center = _rect->_center + Vector2(0.5f,0.5f);
    _rect->Update();

    _circle->_center = _circle->_center + Vector2(0.5f, 0.5f);
    _circle->_radlian = _circle->_radlian + 1.0f;
    _circle->Update();
}

void PaintScene::Update()
{
    //_left += 0.1f; // 왼쪽 면
    //_top += 0.1f; // 위쪽 면
    //_right += 0.1f; // 오른쪽 면
    //_bottom += 0.1f; // 아래쪽 면
}

void PaintScene::Render(HDC hdc)
{
    // 색 입히기 : Red
    HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, redBrush);
    

    //사각형 그리기 
    _rect->Render(hdc);
  

    // 색 입히기 : blue
    HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
    SelectObject(hdc, blueBrush);
    // 원 그리기
    //Ellipse(hdc, 200, 200, 300, 300);
    _circle->Render(hdc);


    // 선 색깔 고르기
    HPEN greenPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
    SelectObject(hdc, greenPen);
    // 선 그리기 
    MoveToEx(hdc, 100, 100, nullptr);
    LineTo(hdc, 200, 200);

}
