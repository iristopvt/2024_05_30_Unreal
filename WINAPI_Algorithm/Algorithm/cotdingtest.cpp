#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";

	for (int i = 1; i <= cipher.length; i++)
	{
		if (i % code ==0)
		{
			answer += cipher[i - 1];
		}
        
	}

    return answer;
}