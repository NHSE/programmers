/*
visited의 경우 변수로 크기를 지정하는 것이 아닌 하드 코딩으로 지정 (정적 배열의 경우)

2단계의 경우 좌 하 우 상의 순서로 우선순위가 정해지기 때문에 이전 dir에 i를 더해 사용하는 것이 아닌
모든 좌표(이동한 좌표 포함)에서 0~3순으로 이동해야만 좌 하 우 상 순으로 이동함
dir을 갱신하며 이동할 경우 상(= 3)에서 i(= 0)이 더해져서 상 좌 하 우의 순으로 이동하기에 문제발생
*/
#include <iostream>
#include <memory>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};

/*
좌 : 좌 하 상 우
하 : 하 우 좌 상
우 : 우 상 하 좌
상 : 상 좌 우 하
*/
int dir_r[4][4] = {{0, 1, -1, 0}, {0, 0, 0, -1}, {0, -1, 1, 0}, {0, 0, 0, 1}}; // 좌 하 우 상
int dir_c[4][4] = {{0, 0, 0, 1}, {0, 1, -1, 0}, {0, 0, 0, -1}, {0, -1, 1, 0}};

int Map[51][51] = {0, };
bool bMap[51][51] = {false, };

int r, c, d = 0;
int N = 0;

struct Data
{
    int r, c, d, depth;
};

int Change_Dir(int dir)
{
    int ret = -1;
    switch(dir)
    {
        case 1 :
            ret = 3;
            break;
        case 2 :
            ret = 1;
            break;
        case 3 :
            ret = 0;
            break;
        case 4 :
            ret = 2;
            break;
    }

    return ret;
}

int Exchange_Dir(int x, int y)
{
    // 좌 하 우 상
    if(x == -1 && y == 0)       return 3; // 상
    else if(x == 1 && y == 0)   return 1; // 하
    else if(x == 0 && y == -1)  return 0; // 좌
    else if(x == 0 && y == 1)   return 2; // 우
    else                        return -1; //그대로
}

bool Check_Map()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(bMap[i][j] == false)  return false;
        }
    }

    return true;
}

bool IsRange(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool Move_Near()
{
    bool ret = false;
    for(int i=0; i<4; i++)
    {
        int d_r = dir_r[d][i];
        int d_c = dir_c[d][i];

        if(d_r == 0 && d_c == 0) // 그대로의 경우
        {
            d_r = dr[d];
            d_c = dc[d];
        }

        int nx = r + d_r;
        int ny = c + d_c;

        //cout << nx << "," << ny << "," << debug_string(d, i) << endl;

        if(!IsRange(nx, ny))    continue;
        if(Map[nx][ny] > 0)     continue;
        if(bMap[nx][ny])        continue;

        r = nx, c = ny;

        int dir = Exchange_Dir(d_r, d_c);
        if(dir != -1)       d = dir;
        bMap[r][c] = true;

        //cout << debug_s() << endl;

        ret = true;
        break;
    }

    return ret;
}

void Move_Beach() // 아직 방문하지 않은 칸 중 가장 가까운 칸 이동
{
    queue<Data> q;
    bool visited[50][50] = {false, };

    visited[r][c] = true;

    q.push({r, c, 0, 0});

    int ret_r = 1e9, ret_c = 1e9, ret_d = 1e9, ret_dir = 1e9;

    while(!q.empty())
    {
        Data data = q.front();
        q.pop();

        if(!bMap[data.r][data.c])
        {
            if(ret_dir > data.depth)
            {
                ret_r = data.r;
                ret_c = data.c;
                ret_dir = data.depth;
                ret_d = data.d;
            }
            else if(ret_dir == data.depth)
            {
                if(ret_r > data.r)
                {
                    ret_r = data.r;
                    ret_c = data.c;
                    ret_d = data.d;
                }
                else if(ret_r == data.r)
                {
                    if(ret_c > data.c)
                    {
                        ret_r = data.r;
                        ret_c = data.c;
                        ret_d = data.d;
                    }
                }
            }
            continue;
        }

        for(int i=0; i<4; i++)
        {
            int nx = data.r + dr[i];
            int ny = data.c + dc[i];

            //cout << data.r << "," << data.c << " -> " << nx << "," << ny << endl;

            if(!IsRange(nx, ny))    continue;
            if(Map[nx][ny] > 0)     continue;
            if(!visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, i, data.depth + 1});
            }
        }
    }

    if(ret_r == 1e9)
    {
        return;
    }

    r = ret_r;
    c = ret_c;
    d = ret_d;

    bMap[r][c] = true;
}

void Move()
{
    //인접탐험
    if(!Move_Near())
    {
        //cout << "Go Beach" << endl;
        //가장 가까운 바다로 이동 (이미 방문한 칸 가능)
        Move_Beach();
    }
}

void debug_Map()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << bMap[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Please write your code here.
    cin >> N >> r >> c >> d;
    r--, c--;

    int t_d = Change_Dir(d);
    d = t_d;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] > 0)  bMap[i][j] = true;
        }
    }

    bMap[r][c] = true;

    //debug_Map();

    while(true)
    {
        cout << r + 1 << " " << c + 1 << "\n";

        if(Check_Map())     break;

        Move();
        //debug_Map();
    }
    return 0;
}