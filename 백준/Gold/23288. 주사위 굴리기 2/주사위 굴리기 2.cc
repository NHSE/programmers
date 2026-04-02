#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int map[21][21];
bool visited[21][21];

int N,M,K;

void Move_Dice(int& x, int& y, int& dir, int& score);
void Dir_Dice(int& x, int& y, int& dir, int south);
int Count_Score(int x, int y);
void Chang_Dice_Num(int dir, vector<int>& dice);

int answer = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin >> map[i][j];
        }
    }

    int x = 1, y = 1, dir = 0, score = 0;
    vector<int> dice = {1, 6, 4, 3, 5, 2};

    while(K--)
    {
        memset(visited, false, sizeof(visited));
        Move_Dice(x, y, dir, score);
        Chang_Dice_Num(dir, dice);
        Dir_Dice(x, y, dir, dice[1]);
        answer += Count_Score(x, y);
    }
    cout << answer;
}

void Move_Dice(int& x, int& y, int& dir, int& score)
{
    int tmp_x, tmp_y;

    tmp_x = x + dx[dir];
    tmp_y = y + dy[dir];

    if(tmp_x < 1 || tmp_y < 1 || tmp_x > N || tmp_y > M)
    {
        dir = ((dir + 2) % 4);
        tmp_x = x + dx[dir];
        tmp_y = y + dy[dir];
    }

    score = map[tmp_x][tmp_y];
    x = tmp_x;
    y = tmp_y;
}

void Dir_Dice(int& x, int& y, int& dir, int south)
{
    if(map[x][y] < south)
    {
        dir = (dir + 1) % 4;
    }
    else if(map[x][y] > south)
    {
        dir = (dir + 3) % 4;
    }
}

int Count_Score(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    visited[x][y] = true;

    int cnt = 0;

    while(!q.empty())
    {
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;
        q.pop();

        cnt++;

        int score = map[tmp_x][tmp_y];

        for(int i=0; i<4; i++)
        {
            int move_x = tmp_x + dx[i];
            int move_y = tmp_y + dy[i];

            if(move_x < 1 || move_y < 1 || move_x > N || move_y > M)    continue;
            if(score != map[move_x][move_y])    continue;

            if(!visited[move_x][move_y])
            {
                visited[move_x][move_y] = true;
                q.push(make_pair(move_x, move_y));
            }
        }
    }
    return map[x][y]*cnt;
}

void Chang_Dice_Num(int dir, vector<int>& dice)
{
    vector<int> tmp_dice;
    switch(dir)
    {
        case 0 : // 동
            tmp_dice.push_back(dice[2]);
            tmp_dice.push_back(dice[3]);
            tmp_dice.push_back(dice[1]);
            tmp_dice.push_back(dice[0]);
            tmp_dice.push_back(dice[4]);
            tmp_dice.push_back(dice[5]);

            dice = tmp_dice;
            break;
        case 1 : //남
            tmp_dice.push_back(dice[5]);
            tmp_dice.push_back(dice[4]);
            tmp_dice.push_back(dice[2]);
            tmp_dice.push_back(dice[3]);
            tmp_dice.push_back(dice[0]);
            tmp_dice.push_back(dice[1]);

            dice = tmp_dice;
            break;
        case 2 : // 서
            tmp_dice.push_back(dice[3]);
            tmp_dice.push_back(dice[2]);
            tmp_dice.push_back(dice[0]);
            tmp_dice.push_back(dice[1]);
            tmp_dice.push_back(dice[4]);
            tmp_dice.push_back(dice[5]);

            dice = tmp_dice;
            break;
        case 3 : // 북
            tmp_dice.push_back(dice[4]);
            tmp_dice.push_back(dice[5]);
            tmp_dice.push_back(dice[2]);
            tmp_dice.push_back(dice[3]);
            tmp_dice.push_back(dice[1]);
            tmp_dice.push_back(dice[0]);

            dice = tmp_dice;
            break;
    }
}