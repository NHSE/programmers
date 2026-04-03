#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

enum {NO=0, YES};

queue<pair<pair<int, int>, tuple<int, int, int>>> q;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};


int N, M, K;

int map[21][21][3];
int shark_go_temp[401][5][5];
int answer = -1;

void BFS();
void map_refresh();
bool map_check();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    int shark_x[M+1];
    int shark_y[M+1];

    int shark_dir[M+1];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int shark, smell;
            cin >> shark;
            if(shark != 0)
            {
                map[i][j][0] = shark;
                map[i][j][1] = K;
                map[i][j][2] = YES;
                shark_x[shark] = i;
                shark_y[shark] = j;
            }
            else
            {
                map[i][j][0] = 0;
                map[i][j][1] = 0;
                map[i][j][2] = NO;
            }
        }
    }

    for(int i=1; i<=M; i++)
    {
        cin >> shark_dir[i];
    }

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=4; j++)
        {
            for(int k=0; k<4; k++)
            {
                int dir;
                cin >> dir;
                shark_go_temp[i][j][k] = dir;
            }
        }
    }

    for(int i=1; i<=M; i++)
    {
        q.push(make_pair(make_pair(shark_x[i], shark_y[i])
                        , make_tuple(i, shark_dir[i], 0)));
    }

    BFS();
    cout << answer;
}

void Copy_map(int map[21][21][3], int copy_map[21][21][3])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<3; k++)
            {
                copy_map[i][j][k] = map[i][j][k];
            }
        }
    }
}

void BFS()
{
    int temp_map[21][21][3];
    Copy_map(map, temp_map);
    int turn = 1;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;

        int cur_shark = get<0>(q.front().second);
        int cur_dir = get<1>(q.front().second);
        int depth = get<2>(q.front().second);

        q.pop();

        if(depth > 1000)   break;

        if(depth == turn)
        {
            Copy_map(temp_map, map);
            map_refresh();
            turn++;
            if(map_check())
            {
                answer = depth;
                break;
            }
            Copy_map(map, temp_map);
        }
    
        bool block = false;
        for(int i=0; i<4; i++)
        {
                int temp_x = x + dx[shark_go_temp[cur_shark][cur_dir][i]];
                int temp_y = y + dy[shark_go_temp[cur_shark][cur_dir][i]];
            
                if(temp_x < 0 || temp_y < 0 || temp_x >= N || temp_y >= N)  continue;

                if(map[temp_x][temp_y][0] == 0 && temp_map[temp_x][temp_y][0] > 0)
                {
                    block = true;
                    temp_map[x][y][2] = NO;
                    break; // 잡아먹힐 칸
                }

                if(map[temp_x][temp_y][0] == 0 && map[temp_x][temp_y][2] == NO) // 빈칸
                {
                    temp_map[temp_x][temp_y][0] = cur_shark;
                    temp_map[temp_x][temp_y][1] = K;
                    temp_map[temp_x][temp_y][2] = YES;

                    temp_map[x][y][2] = NO;

                    q.push(make_pair(make_pair(temp_x, temp_y)
                        , make_tuple(cur_shark, shark_go_temp[cur_shark][cur_dir][i], depth+1)));
                
                    block = true;
                    break;
                }
        }

        if(!block)
        {
            for(int i=0; i<4; i++)
            {
                    int temp_x = x + dx[shark_go_temp[cur_shark][cur_dir][i]];
                    int temp_y = y + dy[shark_go_temp[cur_shark][cur_dir][i]];

                    if(temp_x < 0 || temp_x >= N || temp_y < 0 || temp_y >= N) continue;

                    if(map[temp_x][temp_y][0] == cur_shark) //자기 냄새의 칸에 돌아가기
                    {
                        temp_map[temp_x][temp_y][0] = cur_shark;
                        temp_map[temp_x][temp_y][1] = K;
                        temp_map[temp_x][temp_y][2] = YES;

                        temp_map[x][y][2] = NO;

                        q.push(make_pair(make_pair(temp_x, temp_y)
                            , make_tuple(cur_shark, shark_go_temp[cur_shark][cur_dir][i], depth+1)));
                        break;
                    }
            }
        }
    }
}

void map_refresh()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j][2] == YES) continue;
            if(map[i][j][0] == 0) continue;

            map[i][j][1] -= 1;
            if(map[i][j][1] == 0)
            {
                map[i][j][0] = 0;
            }
        }
    }
}

bool map_check()
{
    bool ret = false;
    bool first_shark = false;
    bool other_shark = false;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j][0] == 1)   first_shark = true;
            else if(map[i][j][0] > 1 && map[i][j][2] == YES)   other_shark = true;
            
            if(other_shark) break;
        }
        if(other_shark) break;
    }
    if(first_shark && !other_shark)     ret = true;

    return ret;
}