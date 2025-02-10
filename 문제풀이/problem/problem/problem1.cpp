#include "iostream"

using namespace std;

#pragma region 연습문제 1
#if 0
int main()
{
	int num = 0;

	cin >> num;

	cout << "멋지군요! 칭찬합니다!" << endl;


}
#endif
#pragma endregion

#pragma region 연습문제 2
#if 0
int main()
{
	int num = 0;

	cin >> num;

	cout << num << "입력했군여" << endl;

}
#endif
#pragma endregion

#pragma region 연습문제 3
#if 0
int main()
{
	int num = 0;

	cin >> num;

	cout << endl;

	cout << num << endl;
	cout << num << endl;
	cout << num << endl;

}
#endif
#pragma endregion

#pragma region 연습문제 4
#if 0
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		cout << a ;
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << b;
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << c;
	}
}
#endif
#pragma endregion


#pragma region 연습문제 5
#if 0

int main()
{
	int num1 = 0;
	int num2 = 0;
	cin >> num1 >> num2;

	cout << num1 - num2;
}


#endif
#pragma endregion

#pragma region 연습문제 7
#if 0

int main()
{
	int a = 0;
	int b = 0;
	
	cin >> a >> b;

	if (a > b)
	{
		cout << "a가 b보다 크다" << endl;
	}
	else
	{
		cout << "b가 a보다 같거나 크다" << endl;
	}
}

#endif
#pragma endregion


#pragma region 연습문제 8
#if 0

int main()
{
	int num;
	int num1;

	cin >> num >> num1;

	if (num > num1)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << num;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			cout << num1;
		}
	}
}

#endif
#pragma endregion


#pragma region 연습문제 10
#if 0

int main()
{
	int num;

	cin >> num;

	if (num > 3)
	{
		num++;
		cout << num;
	}
	else
	{
		num--;
		cout << num;
	}

}

#endif
#pragma endregion

#pragma region 연습문제 11
#if 0

int main()
{

	int num;
	cin >> num;

	if (num > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "###" << endl;
		}
	}
	else if (num == 0)
	{
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "$$$" << endl;
		}
	}

}

#endif
#pragma endregion


#pragma region 연습문제 12
#if 0

int main()
{
	int a,b,c;
	
	cin >> a >> b >> c;

	int add = a + b + c;
	int num = a * b * c;

	if (add >= num)
	{
		cout << "행운의수";
	}
	else
	{
		cout << "소소한수";
	}

}

#endif
#pragma endregion


//#pragma region 연습문제 10
//#if 0

//#endif
//#pragma endregion
