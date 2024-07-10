#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> argument;
vector<string> babble = { "aya","ye","woo","ma" };
vector<bool> visited;
unordered_map<string,int> canBabble;

// babble�� �̿��ؼ� ���� �� �ִ� �ܾ �� ������
// �� ���� �� �ִ� �ܾ� 64����


void DFS(int here, string word)
{
	

	visited[here] = true;
	word += babble[here];

	canBabble[word]=1;

	for (int there = 0; there < 4; there++)
	{
		if (here == there)
			continue;
		if (visited[there] == true )
			continue;
		
		DFS(there, word);
	}

	visited[here] = false;
}

void DFS_ALL()
{
	for (int i = 0; i < 4; i++)
	{
		DFS(i, "");
	}
}

int solution(vector<string> babbling) {

	int answer = 0;
	visited = vector<bool>(4, false);

	DFS_ALL();

	for (auto word : babbling)
	{
		//word�� canbabble�� �ִ�
		// answer ++;
		if (canBabble.count(word) != 0)
			answer++;

	}
	return answer;
}

int main()
{

	cout << solution(argument) << endl;

}