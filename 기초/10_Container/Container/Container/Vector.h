#pragma once

// int
class Vector
{
public:
	Vector()
	{
		// ����
	}
	~Vector()
	{
		// ����
	}

	void Reserve(int capacity)
	{
		// ����
	}
	void PushBack(int value)
	{
		// ����
	}

	void PopBack()
	{
		// ����
	}

	void Clear()
	{
		// ����
	}

	const int& Size() { return _size; }
	const int& Capacity() { return _capacity; }

	int operator[](int index)
	{
		// ����
		return 0;
	}

private:
	int _size = 0;
	int _capacity = 0;
	// ����
	int* _data = nullptr;
};

