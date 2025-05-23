#include <iostream>

using namespace std;

// ��ü ���� 3�Ӽ�
// 1. ���м�
// - public    : ��𼭳� ���� ����
// - private   : ����(����Լ�)������ ���� ����
// - protected : ����, �ڽĿ����� ���� ����
// 
// ...�Ժη� ��������� �ǵ帮������.
// => ���α׷��Ӱ� ���� public ����Լ�(�������̽�)�θ� ��������� �����ض�
// 
// 2. ������
// - �Լ� �����ε�
// 
// - �Լ� �������̵�
// 
// 3. ��Ӽ�
// Animal ... Cat
// Cat�� Animal�ΰ�? (O)
// Animal�� Cat�ΰ�? (X)
//
// 4. �߻�ȭ

class Vector2
{
public:
	Vector2() { _x = 0; _y = 0; }
	Vector2(int x, int y) { _x = x; _y = y; }
	~Vector2() {}

	void PrintVector2()
	{
		// this ������ Ű����
		// �� �Լ��� ȣ���� ��ü�� ����Ű�� ������
		cout << "x : " << (*this)._x << endl;
		cout << "y : " << this->_y << endl;
	}

	// ������ �����ε�
	// a + b : a�� b�� ���ϰ� �� ���� ��ȯ�Ѵ�.

	Vector2 operator+(const Vector2& other)
	{
		Vector2 result;
		result._x = this->_x + other._x;
		result._y = _y + other._y;

		return result;
	}

	// -
	Vector2 operator-(const Vector2& other)
	{
		Vector2 result;
		result._x = this->_x - other._x;
		result._y = _y - other._y;

		return result;
	}

	// vector * scalar
	Vector2 operator*(int value)
	{
		Vector2 result;
		result._x = _x * value;
		result._y = _y * value;

		return result;
	}
	// vector / scalar
	Vector2 operator/(int value)
	{
		Vector2 result;
		result._x = _x / value;
		result._y = _y / value;

		return result;
	}

	// a.operator=(b)
	// a = b : a���ٰ� b�� �����ϰ� a�� ������ ��ȯ�Ѵ�.
	// �������������� �Ϲ������� �����Ǵ�
	Vector2& operator=(const Vector2& other)
	{
		this->_x = other._x;
		this->_y = other._y;

		return (*this);
	}

	// a++
	// �ӽ÷� a�� ���� ��ȯ�ϰ� a�� 1 �����ش�.
	Vector2 operator++(int)
	{
		Vector2 result = *this;
		*this = (*this) + Vector2(1, 1);

		return result;
	}

	// ++a
	// a�� ���� 1 ���ϰ�, a�� ������ ��ȯ�Ѵ�.
	Vector2& operator++()
	{
		(*this)++;
		return (*this);
	}

	// ����, ����
	float Dot(const Vector2& other)
	{
		// cosA * |a| * |b| = _x * other._x + _y * other._y;
		float result = 0.0f;
		result = _x * other._x + _y * other._y;
		return result;
	}

	// ����
	float Cross(const Vector2& other)
	{
		float result = _x * other._y - _y * other._x;
		return result;
	}

	int _x;
	int _y;
};

// ���
class Animal
{
public:
	Animal() { _mouth = 1; _leg = 4; }

	void Eat()
	{
		cout << "����" << endl;
	}

protected:
	int _mouth;
	int _leg;
};

class Cat : public Animal
{
public:
	Cat() 
	{ 
		// :: : ��������������
		Animal::_mouth = 1;
		_tail = 123; 
	}

	// �Լ� �������̵� : �ñ״��İ� ������ �����ϰ� ���๮�� �������Ѵ�.
	void Eat()
	{
		cout << "�ɳ�" << endl;
	}

	// �Լ� �����ε�
	void Eat(int temp)
	{
		cout << temp << endl;
		cout << "�ɳ�" << endl;
	}

private:
	int _tail;
};

int main()
{
	Animal animal = Animal();
	Cat cat = Cat();

	animal.Eat();
	cat.Animal::Eat();

	return 0;
}