#include "pch.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _rect = make_shared<RectCollider>(Vector2(0.0f,0.0f), Vector2(50.0f,50.0f));
    // circle
    _circle = make_shared < CircleCollider>(Vector2(200.0f, 200.0f), 15);



}

PaintScene::~PaintScene()
{

}

void PaintScene::Update()
{
    _rect->_center = _rect->_center + Vector2(0.5f,0.5f); 
    _circle->_center = LERP(_circle->_center, mousePos, 0.1f);//_circle->_center+(mousePos - _circle->_center)*0.1f;

    //_circle->_center = _circle->_center + Vector2(0.5f, 0.5f);
 //   _circle->_radlian = _circle->_radlian + 1.0f; //크기 증감
    _rect->Update();
    _circle->Update();
}

void PaintScene::Render(HDC hdc)
{
   // DeleteObject(redBrush);

  
    _rect->Render(hdc);

  

    // 원 그리기
    //Ellipse(hdc, 200, 200, 300, 300);
 
    _circle->Render(hdc);


}
