#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Data
{
    int node, depth;
};  

bool bmap[20001][20001] = {false, };
int max_depth = -1;
int ret = 0;
int N;

void BFS()
{
    queue<Data> q;
    q.push({1, 0});
    bool visited[20001] = {false, };
    visited[1] = true;
    
    while(!q.empty())
    {
        Data data = q.front();
        q.pop();
        
        cout << data.node << " " << data.depth << endl;
        
        if(max_depth < data.depth)
        {
            max_depth = data.depth;
            ret = 1;
        }
        else if(max_depth == data.depth)
        {
            ret++;
        }
        
        for(int i=0; i<=N; i++)
        {
            if(i == data.node)   continue;
            if(bmap[data.node][i] || bmap[i][data.node])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push({i, data.depth + 1});
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N = n;
    for(int i=0; i<edge.size(); i++)
    {
        int a, b;
        a = edge[i][0], b = edge[i][1];
        bmap[a][b] = true;
        bmap[b][a] = true;
    }
    
    BFS();
    return ret;
}