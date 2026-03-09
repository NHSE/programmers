#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[50][50];
bool visited[50][50];

void DFS(int x, int y);

int m, n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int count = 0;
        cin >> m >> n >> k;

        memset(map, 0x00, sizeof(map));
        memset(visited, false, sizeof(visited));
    
        for(int j=0; j<k; j++)
        {
            int a,b;
            cin >> a >> b;
            map[a][b] = 1;
        }

        for(int x = 0; x<m; x++)
        {
            for(int y=0; y<n; y++)
            {
                if(!visited[x][y] && map[x][y] == 1)
                {
                    count++;
                    DFS(x, y);
                }
            }
        }
        cout << count << "\n";
    }
}

void DFS(int x, int y)
{
    if(visited[x][y])
        return;
    
    visited[x][y] = true;

    for(int i=0; i<4; i++)
    {
        int temp_x = x+dx[i];
        int temp_y = y+dy[i];

        if(temp_x < 0 || temp_y < 0 || temp_x >= m || temp_y >= n)
            continue;

        if(!visited[temp_x][temp_y] && map[temp_x][temp_y] == 1)
        {
            DFS(temp_x, temp_y);
        }
    }
}