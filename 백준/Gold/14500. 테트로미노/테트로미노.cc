#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DFS(int x, int y, int depth, int temp_answer);

int answer = 0;

int map[500][500];
bool visited[500][500] = {false, };

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) // y
    {
        for(int j=0; j<m; j++) // x
        {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            DFS(i, j, 1, 0);
        }
    }
    cout << answer;
}

void DFS(int x, int y, int depth, int temp_answer)
{
    temp_answer += map[x][y];
    visited[x][y] = true;

    if(depth == 4)
    {
        if(answer < temp_answer)
        {
            answer = temp_answer;
        }
        visited[x][y] = false;
        return;
    }

    for(int i=0; i<4; i++)
    {
        int temp_x = x + dx[i];
        int temp_y = y + dy[i];

        if(temp_x < 0 || temp_y < 0 || temp_x >= n || temp_y >= m)
            continue;
        else
        {
            if(!visited[temp_x][temp_y])
            {
                if(depth == 2)
                {
                    temp_answer += map[temp_x][temp_y];
                    for(int j=0; j<4; j++)
                    {
                        if(i%2 != j%2)
                        {
                            int temp__x = x + dx[j];
                            int temp__y = y + dy[j];
                            if(temp__x < 0 || temp__y < 0 || temp__x >= n || temp__y >= m)
                                continue;
                            if(!visited[temp__x][temp__y])
                            {
                                DFS(temp__x, temp__y, 4, temp_answer);
                                visited[temp__x][temp__y] = false;
                            }
                        }
                    }
                    temp_answer -= map[temp_x][temp_y];
                }
                DFS(temp_x, temp_y, depth+1, temp_answer);
                visited[temp_x][temp_y] = false;
            }
        }
    }
    visited[x][y] = false;
}