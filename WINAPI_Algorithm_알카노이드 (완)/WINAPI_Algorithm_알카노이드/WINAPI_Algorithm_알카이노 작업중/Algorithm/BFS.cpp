#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
/*
 BFS


*/

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent;
vector<int> dele;

void CreateGraph_AdjacentMatrix()
{


    adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

    adjacent[0][0] = true;
    adjacent[0][1] = true;
    adjacent[0][2] = true;
    adjacent[0][4] = true;

    adjacent[1][0] = true;
    adjacent[1][1] = true;

    adjacent[2][0] = true;
    adjacent[2][2] = true;
    adjacent[2][3] = true;
    adjacent[2][4] = true;
    adjacent[2][5] = true;

    adjacent[3][2] = true;
    adjacent[3][3] = true;

    adjacent[4][0] = true;
    adjacent[4][2] = true;
    adjacent[4][4] = true;
    adjacent[4][6] = true;

    adjacent[5][2] = true;
    adjacent[5][5] = true;

    adjacent[6][4] = true;
    adjacent[6][6] = true;


}


void BFS(int start)
{
    int N = adjacent.size();
    discovered[start] = true;
    parent[start] = start;

    cout << start << "방문" << endl;

    queue<int> q;
    q.push(start);

    while (true)
    {
        if (q.empty() == true) break;

        int here = q.front();
        q.pop();

        for (int there =0; there< N; there++)
        {
            if (adjacent[here][there] == false)
                continue;
            
            if (discovered[there] == true)            
                continue;

            q.push(there);
            cout << there << " 발견!" << endl;
            discovered[there] = true;
            parent[there] = here;
        }
    }
}

// 5에서 0 까지 갔을때 간선의 수

int edgeCount(int start, int dest) // 최단 거리 구하는
{ 
  //start 0
  // dest 5

    int result = 0;

    while (true)
    {
        if (dest == start)
            break;
            dest = parent[dest];
        result++;
    }

   // BFS(0);
   // 앞쪽 요소에 접근하여서 삭제 삭제 ?

    return result;
}

int main()
{
    CreateGraph_AdjacentMatrix();
    int size = adjacent.size();
    discovered = vector<bool>(7, false);
    parent = vector<int>(size, -1);

    BFS(0);

    return 0;
}
