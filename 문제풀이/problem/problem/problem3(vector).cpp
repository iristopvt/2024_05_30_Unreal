#include "iostream"
#include "vector"

using namespace std;




#pragma region 연습문제 1
#if 0

int main()
{
	vector<int> a(5);

	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] ;
	}
}
#endif
#pragma endregion

#pragma region 연습문제 2
#if 0

int main()
{
	vector<int> a = { 4,1,3,6,9 };

	int b;
	cin >> b;

	cout << b << "번 index의값은"<< a[b] <<"입니다";
}
#endif
#pragma endregion


#pragma region 연습문제 3
#if 0

int main()
{
	vector<int> a(7);

	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}

	cout << a[0] + a[a.size() - 1];

}
#endif
#pragma endregion

#pragma region 연습문제 4
#if 0
int main()
{
	vector<int> a(5);
	int b;
	cin >> b;
	int num = b + 5;

	for (int i = 0; i < a.size(); i++)
	{
		a[i] =num;
	}
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	

}

#endif
#pragma endregion

#pragma region 연습문제 5
#if 0
int main()
{
	vector<int> a = { 3,1,2,5 };
	int b;
	cin >> b;

	if (a[b] > 2)
	{
		cout << "우와";
	}
	else
	{
		cout <<"ㅠㅠ";

	}
}
#endif
#pragma endregion


#pragma region 연습문제 6
#if 0
int main()
{
	vector<int> a = { 5,2,3,4,7 };

	for (int i = 4; i >= 0; i--)
	{
		cout << a[i];
	}
}
#endif
#pragma endregion

#pragma region 연습문제 7
#if 0
int main()
{
	vector<int> a(6);

	int b;
	cin >> b;
	int num = b - 1;

	for (int i = 0; i < a.size(); i++)
	{
		a[i] = b - i;
	}

	cout << a[2];

}
#endif
#pragma endregion


#pragma region 연습문제 8
#if 0
int main()
{
	vector<int> arr = { 5,25,54,2,-33,57,82,-8,13,1 };

	int index;
	cin >> index;

	for (int i = index; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}
#endif
#pragma endregion