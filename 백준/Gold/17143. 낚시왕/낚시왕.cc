#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

struct Node
{
    int x, y, s, d, z;
};

int map[102][102];
queue<Node> shark;
pair<int, int> p[10001];

int R, C, M;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

void BFS()
{
    int temp_map[102][102];
    queue<Node> shark_temp;

    fill(&temp_map[0][0], &temp_map[0][0] + 102*102, 0);

    while(!shark.empty())
    {
        Node node = shark.front();
        shark.pop();

        if(map[node.x][node.y] != node.z)
            continue;
        
        int cycle = (node.d <= 2) ? (R - 1) * 2 : (C - 1) * 2;
        int move = node.s % cycle;

        for (int i = 0; i < move; i++) 
        {
            int nx = node.x + dx[node.d];
            int ny = node.y + dy[node.d];
        
            if (nx < 1 || nx > R || ny < 1 || ny > C) 
            {
                // 방향만 바꿈, 이동은 아직 안 함
                if (node.d == 1) node.d = 2;
                else if (node.d == 2) node.d = 1;
                else if (node.d == 3) node.d = 4;
                else if (node.d == 4) node.d = 3;
            }
        
            // 방향이 바뀌었든 아니든, 이제 이동
            node.x += dx[node.d];
            node.y += dy[node.d];
        }
        if(temp_map[node.x][node.y] > 0)
        {
            if(temp_map[node.x][node.y] < node.z)
            {
                temp_map[node.x][node.y] = node.z;
            }
        }
        else
        {
            temp_map[node.x][node.y] = node.z;
        }

        shark_temp.push(node);
    }
    memcpy(map, temp_map, sizeof(temp_map));
    shark = shark_temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;

    fill(&map[0][0], &map[0][0] + 102*102, 0);
    for(int i=0; i<M; i++)
    {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        map[x][y] = z;

        Node node;
        node.x = x;
        node.y = y;
        node.s = s;
        node.d = d;
        node.z = z;
        shark.push(node);
    }

    int answer = 0;
    int i = 1;
    while(i <= C)
    {
        for(int j=1; j<=R; j++)
        {
            if(map[j][i] != 0)
            {
                answer += map[j][i];
                map[j][i] = 0;
                break;
            }
        }
        BFS();
        i++;
    }
    cout << answer;
}