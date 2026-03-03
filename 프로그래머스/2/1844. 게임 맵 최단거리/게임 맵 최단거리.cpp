#include<vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

struct Data
{
    int r, c, depth;  
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> Map;
bool visited[100][100] = {false, };

bool IsRange(int r, int c)
{
    return r >= 0 && r < N && c >= 0 && c < M;
}

int Move()
{
    int ret = -1;
    
    queue<Data> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while(!q.empty())
    {
        Data data = q.front();
        q.pop();
        
        if(data.r == N-1 && data.c == M-1)
        {
            ret = data.depth;
            break;
        }
        
        for(int i=0; i<4; i++)
        {
            int nr = data.r + dx[i];
            int nc = data.c + dy[i];
            
            if(!IsRange(nr, nc))    continue;
            if(Map[nr][nc] == 0)    continue;
            if(!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({nr, nc, data.depth + 1});
            }
        }
    }
    
    return ret;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    memset(visited, false, sizeof(visited));
    Map = maps;
    N = Map.size(), M = Map[0].size();
    
    answer = Move();
    
    return answer;
}