#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

int map[8][8];
int backup_map[8][8];

bool visited[8][8] = {false, };

int n, m, cnt = 0;
int min_sum = 1e9;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void DFS(int depth);
void cctv_watch(int dir, int i, int j);
void check();

void debug()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << map[i][j] << " ";       
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6)
            {
                cnt += 1;
            }
        }
    }
    DFS(0);
    cout << min_sum;
}

void DFS(int depth)
{
    if(depth == cnt)
    {
        //debug();
        check();
        return;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(map[i][j] > 0 && map[i][j] < 6 && !visited[i][j])
            {
                int dir = 0;
                if(map[i][j] == 1 || map[i][j] == 3 || map[i][j] == 4)
                {
                    dir = 4;
                }
                else if(map[i][j] == 2)
                {
                    dir = 2;
                }
                else
                {
                    dir = 1;
                }

                visited[i][j] = true;
                for(int k=0; k<dir; k++)
                {
                    int backup[8][8];
                    memcpy(backup, map, sizeof(map));
                    cctv_watch(k, i, j);
                    DFS(depth+1);
                    memcpy(map, backup, sizeof(map));
                }
                visited[i][j] = false;
                return;
            }
        }
    }
}

void cctv_watch(int dir, int i, int j)
{
    int temp_i = i;
    int temp_j = j;

    if(map[i][j] == 1)
    {
        int ni = i, nj = j;
        while (true)
        {
            ni += dx[dir];
            nj += dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }
    }
    else if (map[i][j] == 2)
    {
        int back_dir = (dir + 2) % 4;

        // 정방향
        int ni = i, nj = j;
        while (true)
        {
            ni += dx[dir];
            nj += dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        // 반대 방향
        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }
    }
    else if (map[i][j] == 3)
    {
        int back_dir = (dir + 3) % 4;

        // 정방향
        int ni = i, nj = j;
        while (true)
        {
            ni += dx[dir];
            nj += dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        // 반대 방향
        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }
    }
    else if (map[i][j] == 4)
    {
        int back_dir = (dir + 3) % 4;

        // 정방향
        int ni = i, nj = j;
        while (true)
        {
            ni += dx[dir];
            nj += dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        back_dir = (dir + 2) % 4;

        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }
    }
    else if (map[i][j] == 5)
    {
        // 정방향
        int back_dir = (dir + 3) % 4;

        // 정방향
        int ni = i, nj = j;
        while (true)
        {
            ni += dx[dir];
            nj += dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        back_dir = (dir + 2) % 4;

        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }

        back_dir = (dir + 1) % 4;

        ni = i, nj = j;
        while (true)
        {
            ni += dx[back_dir];
            nj += dy[back_dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 6)
                break;
            if (map[ni][nj] == 0)
                map[ni][nj] = 9;
        }
    }
}

void check()
{
    int answer = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(map[i][j] == 0)
            {
                answer++;
            }
        }
    }
    if(answer < min_sum)
    {
        min_sum = answer;
    }
}