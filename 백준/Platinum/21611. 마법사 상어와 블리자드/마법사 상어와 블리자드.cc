#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct shark_index
{
    int x, y;
};

int map[50][50];

int N, M;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

shark_index shark;

vector<int> boom_cnt(5, 0);

int answer = 0;

void debug(string s)
{
    cout << "--------------- " << s << " -------------" << endl;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Blizzard(int d, int s)
{
    int x = shark.x;
    int y = shark.y;
    for(int i=0; i<s; i++)
    {
        x += dx[d];
        y += dy[d];
        
        if(x < 1 || y < 1 || x > N || y > N)    break;

        map[x][y] = 0;
    }
    //debug("Blizzard");
}

void Bead_Move()
{
    int tmp_map[50][50] = {0, };

    int x = shark.x;
    int y = shark.y;

    int tmp_x = x;
    int tmp_y = y;

    int cnt = 0;
    int tmp_cnt = 0;
    int temp = 0;

    int dir = 0;
    int tmp_dir = 0;

    int seq[4] = {3, 2, 4, 1};

    bool flag = false;

    while(!flag)
    {
        if(seq[dir%4]%4 == 3)  cnt++;
        else if(seq[dir%4]%4 == 0) cnt++;

        for(int i=0; i<cnt; i++)
        {
            x += dx[seq[dir%4]];
            y += dy[seq[dir%4]];

            if(x < 1 || y < 1 || x > N || y > N)
            {
                flag = true;
                break;
            }


            if(map[x][y] != 0)
            {
                if(temp == 0)
                {  
                    tmp_cnt++;
                    temp = tmp_cnt * 2;
                }

                tmp_x += dx[seq[tmp_dir%4]];
                tmp_y += dy[seq[tmp_dir%4]];

                if(tmp_x < 1 || tmp_y < 1 || tmp_x > N || tmp_y > N)
                {
                    flag = true;
                    break;
                }

                tmp_map[tmp_x][tmp_y] = map[x][y];
                temp--;
                
                if(temp == tmp_cnt || temp == 0)
                {
                    tmp_dir++;
                }
            }
        }
        dir++;
    }
    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            map[i][j] = tmp_map[i][j];
        }
    }
    //debug("Bead_Move");
}

void Boom_Bead()
{
    int x = shark.x;
    int y = shark.y;

    int cnt = 0;

    int dir = 0;

    int seq[4] = {3, 2, 4, 1};

    int before_value = 0;
    int same_bead_cnt = 0;

    vector<shark_index> v;

    bool flag = false;

    while(!flag)
    {
        if(seq[dir%4]%4 == 3)  cnt++;
        else if(seq[dir%4]%4 == 0) cnt++;

        for(int i=0; i<cnt; i++) 
        {
            x += dx[seq[dir%4]];
            y += dy[seq[dir%4]];

            if(x < 1 || y < 1 || x > N || y > N)
            {
                flag = true;
                break;
            }

            if(before_value != map[x][y])
            {
                if(same_bead_cnt > 3)
                {
                    for(int i=0; i<v.size(); i++)
                    {
                        int tmp_x = v[i].x;
                        int tmp_y = v[i].y;

                        boom_cnt[map[tmp_x][tmp_y]]++;
                        map[tmp_x][tmp_y] = 0;
                    }
                }
                before_value = map[x][y];
                same_bead_cnt = 1;
                v.clear();
                v.push_back({x, y});
            }
            else
            {
                v.push_back({x, y});
                same_bead_cnt++;
            }
        }
        dir++;
    }
    if(same_bead_cnt >= 4)
    {
        for(int i=0; i<v.size(); i++)
        {
            int tmp_x = v[i].x;
            int tmp_y = v[i].y;

            boom_cnt[map[tmp_x][tmp_y]]++;
            map[tmp_x][tmp_y] = 0;
        }
    }
    //debug("Boom_Bead");
}

void Bead_Refresh(vector<int> info, int tmp_map[50][50])
{
    int x = shark.x;
    int y = shark.y;

    int cnt = 0;
    int dir = 0;
    int seq[4] = {3, 2, 4, 1};

    int k = 0;

    bool flag = false;

    while(1)
    {
        if(seq[dir%4]%4 == 3)  cnt++;
        else if(seq[dir%4]%4 == 0) cnt++;

        for(int i=0; i<cnt; i++)
        {
            x += dx[seq[dir%4]];
            y += dy[seq[dir%4]];

            if(x > N || y > N || x < 1 || y < 1 || k >= info.size() || k >= (N*N) - 1)
            {
                flag = true;
                break;
            }

            tmp_map[x][y] = info[k];
            k++;
        }
        dir++;
        if(flag)    break;
    }
}

void Bead_Amplification()
{
    int tmp_map[50][50] = {0, };

    int x = shark.x;
    int y = shark.y;

    int tmp_x = x;
    int tmp_y = y;

    int cnt = 0;
    int tmp_cnt = 0;

    int dir = 0;
    int tmp_dir = 0;

    int before_value = 0;
    int same_bead_cnt = 0;

    int seq[4] = {3, 2, 4, 1};

    int tmp_index = 0;

    bool flag = false;

    vector<int> info;

    while(!flag)
    {
        if(seq[dir%4]%4 == 3)  cnt++;
        else if(seq[dir%4]%4 == 0) cnt++;

        for(int i=0; i<cnt; i++)
        {
            x += dx[seq[dir%4]];
            y += dy[seq[dir%4]];

            if(x < 1 || y < 1 || x > N || y > N)
            {
                flag = true;
                break;
            }

            if(before_value == map[x][y])
            {
                same_bead_cnt++;
            }
            else
            {
                if(same_bead_cnt > 0)
                {
                    info.push_back(same_bead_cnt);
                    info.push_back(before_value);
                }
                before_value = map[x][y];
                same_bead_cnt = 1;
            }
        }
        dir++;
    }

    Bead_Refresh(info, tmp_map);

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            map[i][j] = tmp_map[i][j];
        }
    }
    //debug("Bead_Amplification");
}

bool check()
{
    int x = shark.x;
    int y = shark.y;

    int cnt = 0;
    int dir = 0;
    int seq[4] = {3, 2, 4, 1};

    int before_value = -1;  // ← 0이 아니라 음수 등 존재하지 않는 값으로 초기화
    int same_bead_cnt = 0;

    bool flag = false;

    while (!flag)
    {
        if (seq[dir % 4] % 4 == 3) cnt++;
        else if (seq[dir % 4] % 4 == 0) cnt++;

        for (int i = 0; i < cnt; i++)
        {
            x += dx[seq[dir % 4]];
            y += dy[seq[dir % 4]];

            if (x < 1 || y < 1 || x > N || y > N)
            {
                flag = true;
                break;
            }

            int cur = map[x][y];
            if (cur == 0) continue;

            if (before_value == -1)
            {
                before_value = cur;
                same_bead_cnt = 1;
            }
            else if (before_value == cur)
            {
                same_bead_cnt++;
            }
            else
            {
                if (same_bead_cnt >= 4) return true;
                before_value = cur;
                same_bead_cnt = 1;
            }
        }
        dir++;
    }

    // 마지막 그룹 체크
    if (same_bead_cnt >= 4) return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> map[i][j];
        }
    }

    shark.x = (N/2) + 1;
    shark.y = shark.x;

    for(int i=0; i<M; i++)
    {
        int d, s;
        cin >> d >> s;

        Blizzard(d, s);
        Bead_Move();

        while(check())
        {
            Boom_Bead();
            Bead_Move();
        }

        Bead_Amplification();
    }

    for(int i=1; i<4; i++)
    {
        answer += i*boom_cnt[i];
    }

    cout << answer;
}