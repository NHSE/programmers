#include <iostream>
#include <vector>

using namespace std;

vector<int> dice(6, 0);
int pan[21][21];
int x = 0;
int y = 0;

int n, m, k;

void move(int cmd);
bool exception_check(int cmd);
void print_dice();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> k;

    for(int x=0; x<n; x++)
    {
        for(int y=0;y<m; y++)
        {
            cin >> pan[x][y];
        }
    }

    for(int i=0; i<k; i++)
    {
        int cmd;
        cin >> cmd;
        if(exception_check(cmd))
        {
            move(cmd);
            print_dice();
            cout << dice[0] << "\n";
        }
    }
}

void move(int cmd)
{
    int temp = dice[0];
    switch (cmd)
    {
        case 1 : //동
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
            y++;
            break;
        
        case 2 :
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
            y--;
            break;

        case 3 :
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
            x--;
            break;

        case 4 :
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
            x++;
            break;
    }
}

bool exception_check(int cmd)
{
    if(cmd == 1 && y + 1 >= m)
    {
        return false;
    }
    if(cmd == 2 && y - 1 < 0)
    {
        return false;
    }
    if(cmd == 3 && x - 1 < 0)
    {
        return false;
    }
    if(cmd == 4 && x + 1 >= n)
    {
        return false;
    }
    return true;
}

void print_dice()
{
    if(pan[x][y] != 0)
    {
        dice[5] = pan[x][y];
        pan[x][y] = 0;
    }
    else
    {
        pan[x][y] = dice[5];
    }
}