#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

char map_RGB[100][100];
char map_RB[100][100];

bool visited[100][100] = {0, };

vector<int> result;

static void DFS(int x, int y, char map, bool check);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;

        for(int j=0; j<n; j++)
        {
            map_RGB[i][j] = s[j];

            if(s[j] == 'G')
            {
                map_RB[i][j] = 'R';
            }
            else
            {
                map_RB[i][j] = s[j];
            }
        }
    }

    int count = 0;
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            if(!visited[x][y])
            {
                count++;
                DFS(x, y, map_RGB[x][y], true);
            }
        }
    }
    result.push_back(count);
    count = 0;
    memset(visited, false, sizeof(visited));

    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            if(!visited[x][y])
            {
                count++;
                DFS(x, y, map_RB[x][y], false);
            }
        }
    }
    result.push_back(count);

    for(auto& it : result)
    {
        cout << it << " ";
    }
}

void DFS(int x, int y, char map, bool check)
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
        
        if(check)
        {
            if(!visited[temp_x][temp_y] && map_RGB[temp_x][temp_y] == map)
            {
                DFS(temp_x, temp_y, map, true);
            }
        }
        else
        {
            if(!visited[temp_x][temp_y] && map_RB[temp_x][temp_y] == map)
            {
                DFS(temp_x, temp_y, map, false);
            }
        }
    }
}