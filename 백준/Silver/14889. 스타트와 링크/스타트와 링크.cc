#include <iostream>
#include <vector>

using namespace std;

int n;
int map[21][21];
bool check[21] = {false, };

void DFS(int start, int depth);
void update();

int answer = 1e9;
vector<int> start_team;
vector<int> link_team;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
        }
    }

    start_team.resize((n/2)+1, 0);
    link_team.resize((n/2)+1, 0);

    DFS(1, 1);
    cout << answer;
}

void DFS(int start, int depth)
{
    check[start] = true;
    start_team[depth] = start;

    if(depth == n/2)
    {
        int link_it = 1;
        for(int i=1; i<=n; i++)
        {
            if(!check[i])
            {
                link_team[link_it] = i;
                link_it++;
            }
        }
        update();
        check[start] = false;
        return;
    }

    for(int i=start+1; i<=n; i++)
    {
        if(!check[i])
        {
            DFS(i, depth+1);
        }
    }
    check[start] = false;
}

void update()
{
    int start_team_sum = 0;
    int link_team_sum = 0;
    for(int i=1; i<=n/2; i++)
    {
        for(int j=1; j<=n/2; j++)
        {
            if(i != j)
            {
                start_team_sum += map[start_team[i]][start_team[j]];
                link_team_sum += map[link_team[i]][link_team[j]];
            }
        }
    }

    if(answer > abs(start_team_sum - link_team_sum))
    {
        answer = abs(start_team_sum - link_team_sum);
    }
}
