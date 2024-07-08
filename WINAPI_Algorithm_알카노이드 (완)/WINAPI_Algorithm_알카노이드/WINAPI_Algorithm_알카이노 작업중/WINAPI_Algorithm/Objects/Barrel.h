#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetStartI(Vector2 start); // �跲 ����  ��ġ ����
	void SetAngle(float angle); // �跲 ���� ����

	Vector2 GetEndPos() { return _line->_end; }  // ����
	Vector2 GetDirection() { return _direction; } //����
	

private:
	shared_ptr<Line> _line;

	float _barrelLength = 100.0f; //�跲 ����
	Vector2 _direction = Vector2(1, 0); // �跲 ���� 

};

