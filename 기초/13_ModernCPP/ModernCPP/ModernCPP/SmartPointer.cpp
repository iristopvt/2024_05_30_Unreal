#include <iostream>
#include <memory>

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// shared_ptr

// weak_ptr

// unique_ptr

class Player
{
public:
	Player() { cout << "�⺻������ ȣ��" << endl; }
	Player(int hp) : _hp(hp) { cout << "Ÿ�� ��ȯ ������ ȣ��" << endl; }
	~Player() { cout << "�Ҹ��� ȣ��" << endl;  }

	void Attack()
	{
		if (target.expired() == false)
		{
			target.lock()->_hp -= 10;
			cout << "����!!!" << endl;
		}
	}

	void SetTarget(shared_ptr<Player> target)
	{
		this->target = target;
	}

private:
	weak_ptr<Player> target;

	int _hp = 0;
};

#pragma region MySharedPtr
struct RefCountBlock
{
	int refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr) : _block(nullptr), _ptr(ptr)
	{
		_block = new RefCountBlock();
		cout << "RefCount : " << _block->refCount << endl;
	}

	SharedPtr(const SharedPtr<T>& other)
	: _ptr(other._ptr)
	, _block(other._block)
	{
		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}
	}

	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->refCount--;
			cout << "RefCount : " << _block->refCount << endl;

			if (_block->refCount <= 0)
			{
				delete _block;
				delete _ptr;
				_ptr = nullptr;
			}
		}
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}

		return (*this);
	}

	T* operator->()
	{
		if (_ptr != nullptr)
			return _ptr;
		return nullptr;
	}

private:
	RefCountBlock* _block;
	T* _ptr;
};

void PrintPlayer(SharedPtr<Player> player)
{
	// cout <<  << endl;
}
#pragma endregion

int main()
{
	shared_ptr<Player> p1 = make_shared<Player>(5);
	shared_ptr<Player> p2 = make_shared<Player>(10);

	// shared_ptr�� ��ȯ ����
	// => weak_ptr�� �ذ�
	p1->SetTarget(p2);
	p2->SetTarget(p1);

	p1->Attack();
	p2->Attack();

	// unique_ptr
	unique_ptr<Player> p3 = make_unique<Player>();


	return 0;
}