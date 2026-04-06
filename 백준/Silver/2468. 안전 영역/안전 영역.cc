#include <iostream>
#include <string.h>

using namespace std;

int map[100][100];
bool visited[100][100] = {0, };

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; 

void DFS(int x, int y, int height);

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int y=0; y<n; y++)
    {
        for(int x=0; x<n; x++)
        {
            cin >> map[x][y];
        }
    }


    int max_ = 0;
    for(int h=1; h<101; h++)
    {
        int cnt = 0;
        for(int y=0; y<n; y++)
        {
            for(int x=0; x<n; x++)
            {
                if(!visited[x][y] && map[x][y] >= h)
                {
                    cnt++;
                    DFS(x, y, h);
                }
            }
        }
        memset(visited, false, sizeof(visited));
        if(max_ <= cnt)
        {
            max_ = cnt;
        }
    }
    cout << max_;
}

void DFS(int x, int y, int height)
{
    if(visited[x][y])
        return;
    
    visited[x][y] = true;

    for(int i=0; i<4; i++)
    {
        int temp_x = x + dx[i];
        int temp_y = y + dy[i];

        if(temp_x < 0 || temp_y < 0 || temp_x >= n || temp_y >= n)
            continue;
        
        if(!visited[temp_x][temp_y] && map[temp_x][temp_y] >= height)
        {
            DFS(temp_x, temp_y, height);
        }
    }
}