#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<int>> Map;

struct Data
{
    int r, c;
};

bool IsRange(int r, int c)
{
    return r >= 0 && r < M && c >= 0 && c < N;
}

bool visited[100][100] = {false, };

int BFS(int r, int c, int num)
{
    int cnt = 0;
    
    queue<Data> q;
    q.push({r, c});
    visited[r][c] = true;
    
    while(!q.empty())
    {
        Data data = q.front();
        q.pop();
        
        cnt++;
        
        for(int i=0; i<4; i++)
        {
            int nr = data.r + dx[i];
            int nc = data.c + dy[i];
            
            if(!IsRange(nr, nc))    continue;
            
            if(num == Map[nr][nc] && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    return cnt;
}

void debug()
{
    for(int r=0; r<M; r++)
    {
        for(int c=0; c<N; c++)
        {
            cout << visited[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    N = n, M = m;
    memset(visited, false, sizeof(visited));
    Map = picture;
    
    for(int r=0; r<M; r++)
    {
        for(int c=0; c<N; c++)
        {
            if(picture[r][c] != 0 && !visited[r][c])
            {
                int value = BFS(r, c, picture[r][c]);
                max_size_of_one_area = max(max_size_of_one_area, value);
                ++number_of_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    
    return answer;
}