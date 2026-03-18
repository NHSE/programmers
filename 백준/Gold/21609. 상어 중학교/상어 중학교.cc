#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Block_index
{
    int x, y; // 행, 열
};

int map[21][21] = {0, };
bool sub_map[21][21] = {false, };
bool visited[21][21] = {false, };

pair<int, int> block = {100, 100};
vector<Block_index> remove_block;

int N, M;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int answer = 0;

void BFS(int x, int y, int& value, int& rainbow_cnt)
{
    queue<pair<int, int>> q;
    pair<int, int> temp_block = {100, 100};
    vector<Block_index> remove_block_tmp;
    bool visited_rainbow[21][21] = {false, };

    q.push({x, y});

    int block_size = 1;
    int rainbow_block = 0;

    visited[x][y] = true;

    while(!q.empty())
    {
        int _x = q.front().first;
        int _y = q.front().second;
        q.pop();

        remove_block_tmp.push_back({_x, _y});

        if(temp_block.first > _x && map[_x][_y] != 0)
        {
            temp_block.first = _x;
            temp_block.second = _y;
        }
        else if(temp_block.first == _x && map[_x][_y] != 0)
        {
            if(temp_block.second > _y)
            {
                temp_block.first = _x;
                temp_block.second = _y;
            }
        }

        for(int i=0; i<4; i++)
        {
            int temp_x = _x + dx[i];
            int temp_y = _y + dy[i];

            if(temp_x < 0 || temp_y < 0 || temp_x >= N || temp_y >= N)  continue;
            if(map[temp_x][temp_y] == -1)   continue;
            if(map[temp_x][temp_y] > M)   continue;
            if(map[temp_x][temp_y] > 0 && map[temp_x][temp_y] != map[x][y])   continue;

            if(!visited[temp_x][temp_y] && !visited_rainbow[temp_x][temp_y])
            {
                if(map[temp_x][temp_y] == 0)
                {
                    rainbow_block++;
                    visited_rainbow[temp_x][temp_y] = true;
                }
                else    visited[temp_x][temp_y] = true;
                block_size++;
                q.push(make_pair(temp_x, temp_y));
            }
        }
    }

    if(value < block_size)
    {
        block.first = temp_block.first;
        block.second = temp_block.second;
        rainbow_cnt = rainbow_block;
        value = block_size;
        remove_block = remove_block_tmp;
    }
    else if(value == block_size)
    {
        if(rainbow_block > rainbow_cnt)
        {
            block.first = temp_block.first;
            block.second = temp_block.second;
            rainbow_cnt = rainbow_block;
            remove_block = remove_block_tmp;
        }
        else if(rainbow_block == rainbow_cnt)
        {
            if(temp_block.first > block.first)
            {
                block.first = temp_block.first;
                block.second = temp_block.second;
                remove_block = remove_block_tmp;
            }
            else if(temp_block.first == block.first)
            {
                if(temp_block.second > block.second)
                {
                    block.second = temp_block.second;
                    remove_block = remove_block_tmp;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }

    while(1)
    {
        int value = 0;
        int rainbow_cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(!visited[i][j] && map[i][j] > 0 && map[i][j] < M+1)
                {
                    BFS(i, j, value, rainbow_cnt);
                }
            }
        }

        if(value < 2)   break;
        answer += value*value;


        for(int i=0; i<remove_block.size(); i++)
        {
            map[remove_block[i].x][remove_block[i].y] = M+1;
        }

        for(int j=0; j<N; j++)
        {
            for(int i=N-2; i>=0; i--)
            {
                int map_value = map[i][j];
                if (map_value <= M && map_value >= 0)
                {
                    int tmp_x = i;
                    while(1)
                    {
                        tmp_x += dx[1];

                        if(map[tmp_x][j] != M+1 || tmp_x == N || map[tmp_x][j] == -1)
                            break;
                        else
                        {
                            if (map[tmp_x][j] == M+1)
                            {
                                map[tmp_x - 1][j] = M + 1;
                                map[tmp_x][j] = map_value;
                            }
                        }
                    }
                }
            }
        }

        int tmp_map[21][21];
        memset(tmp_map, 0, sizeof(tmp_map));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                tmp_map[(N-1)-j][i] = map[i][j];
            }
        }
        memcpy(map, tmp_map, sizeof(tmp_map));

        for(int j=0; j<N; j++)
        {
            for(int i=N-2; i>=0; i--)
            {
                int map_value = map[i][j];
                if (map_value <= M && map_value >= 0)
                {
                    int tmp_x = i;
                    while(1)
                    {
                        tmp_x += dx[1];  // dx[1] == 1 -> 아래로 이동

                        if(tmp_x == N || map[tmp_x][j] != M+1 || map[tmp_x][j] == -1)
                            break;
                        else
                        {
                            if (map[tmp_x][j] == M+1)
                            {
                                map[tmp_x - 1][j] = M + 1;
                                map[tmp_x][j] = map_value;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << answer;
}
