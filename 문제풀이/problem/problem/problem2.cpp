#include "iostream"

using namespace std;



#pragma region 연습문제 1
#if 0

int main()
{
	int num, num1;

	cin >> num >> num1;

	if (num > num1)
	{
		cout << "큰수는" << num;
	}
	else if (num == num1)
	{
		cout << "같은숫자";
	}
	else if (num < num1)
	{
		cout << "큰수는" << num1;
	}
}
#endif
#pragma endregion


#pragma region 연습문제 2
#if 0

int main()
{
	int num;
	cin >> num;

	if (num == 5 || num == 10)
	{
		cout << "만세" << endl;
	}
	else
	{
		cout << "재도전" << endl;
	}
}
#endif
#pragma endregion



#pragma region 연습문제 3
#if 0

int main()
{
	int num, num1;

	cin >> num >> num1;

	for (int i = num; i <= num1; i++)
	{
		cout << i << endl;

	}
}
#endif
#pragma endregion



#pragma region 연습문제 4
#if 0

int main()
{
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cout << "##" << endl;

	}
}

#endif
#pragma endregion



#pragma region 연습문제 5
#if 0

int main()
{

	int a, b, c;
	cin >> a >> b >> c;

	int add = a + b + c;
	int num = a* b* c;

	if (add > 10)
	{
		cout << num << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}
#endif
#pragma endregion


#pragma region 연습문제 6
#if 0

int main()
{
	int a;
	cin >> a;

	for (int i = a; i >= 0; i--)
	{
		cout << i << endl;
		if (i == 0)
		{
			cout << "발사";
		}
	}
}
#endif
#pragma endregion


