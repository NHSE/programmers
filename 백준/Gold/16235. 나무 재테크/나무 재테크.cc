#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> Node;

bool cmp(int a, int b)
{
    return a < b;
}

int map[12][12];
int S2D2[11][11];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

vector<int> tree_list[11][11];
queue<Node> die_tree;

int N, M, K;

void spring();
void summer();
void fall();
void winter();
void grow_tree(int x, int y);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    fill(&map[0][0], &map[N+1][N+1], 5);

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> S2D2[i][j];
        }
    }

    for(int i=0; i<M; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree_list[x][y].push_back(age);
    }

    while(K > 0)
    {
        spring();
        summer();
        fall();
        winter();
        K--;
    }
    int answer = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			answer = answer + tree_list[r][c].size();
		}
	}
	cout << answer;
}

void spring()
{
    for (int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            sort(tree_list[i][j].begin(), tree_list[i][j].end(), cmp);
        }
    }
    for (int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            vector<int> temp_list;
            for(int z=0; z<tree_list[i][j].size(); z++)
            {
                int x = i;
                int y = j;
                int age = tree_list[i][j][z];


                if(map[x][y] >= age)
                {
                    map[x][y] -= age;
                    temp_list.push_back(age+1);
                }
                else
                {
                    die_tree.push(make_tuple(x, y, age));
                }
            }
            tree_list[i][j] = temp_list;
        }
    }
}

void summer()
{
    queue<Node> temp_die;
    while(!die_tree.empty())
    {
        int x = get<0>(die_tree.front());
        int y = get<1>(die_tree.front());
        int age = get<2>(die_tree.front());
        die_tree.pop();

        map[x][y] += age/2;
    }
}

void fall()
{
    for (int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            for(int z=0; z<tree_list[i][j].size(); z++)
            {
                int x = i;
                int y = j;
                int age = tree_list[i][j][z];
    
                if(age > 0 && age%5 == 0)
                {
                    grow_tree(x, y);
                }
            }
        }
    }
}

void winter()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            map[i][j] += S2D2[i][j];
        }
    }
}

void grow_tree(int x, int y)
{
    for(int i=0; i<8; i++)
    {
        int temp_x = x + dx[i];
        int temp_y = y + dy[i];

        if(temp_x < 1 || temp_y < 1 || temp_x > N || temp_y > N)
            continue;

        tree_list[temp_x][temp_y].push_back(1);
    }
}