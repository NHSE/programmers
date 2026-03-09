#include <iostream>
#include <deque>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N, M, T;
int answer;

deque<deque<int>> cir;

bool BFS(int x, int y, int value);
void Turn_cir(int xi, int di, int ki);
void average_check();
void Refresh_cir(double average);
void Answer();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;

    cir.resize(N + 1, deque<int>(M, 0));
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            cin >> cir[i][j];

    for (int i = 0; i < T; i++)
    {
        int xi, di, ki;
        cin >> xi >> di >> ki;
        Turn_cir(xi, di, ki);
        bool check = false;

        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (cir[j][k] == 0) continue;
                if (BFS(j, k, cir[j][k])) check = true;
            }
        }

        if (!check)
            average_check();
    }

    Answer();
    cout << answer;
}

void Turn_cir(int xi, int di, int ki)
{
    ki %= M;
    for (int i = xi; i <= N; i += xi)
    {
        if (di == 0) // 시계 방향
        {
            for (int t = 0; t < ki; t++)
            {
                int temp = cir[i].back();
                cir[i].pop_back();
                cir[i].push_front(temp);
            }
        }
        else // 반시계 방향
        {
            for (int t = 0; t < ki; t++)
            {
                int temp = cir[i].front();
                cir[i].pop_front();
                cir[i].push_back(temp);
            }
        }
    }
}

bool BFS(int x, int y, int value)
{
    bool ret = false;
    queue<pair<int, int>> q;
    vector<pair<int, int>> to_erase;
    vector<vector<bool>> visited(N + 1, vector<bool>(M, false));

    q.push(make_pair(x, y));
    visited[x][y] = true;
    to_erase.push_back(make_pair(x, y));

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > N) continue;
            if (ny < 0) ny = M - 1;
            if (ny >= M) ny = 0;
            if (visited[nx][ny]) continue;
            if (cir[nx][ny] == value)
            {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                to_erase.push_back(make_pair(nx, ny));
                ret = true;
            }
        }
    }

    if (ret)
    {
        for (int i = 0; i < to_erase.size(); i++)
        {
            int r = to_erase[i].first;
            int c = to_erase[i].second;
            cir[r][c] = 0;
        }
    }

    return ret;
}

void average_check()
{
    double average = 0.0;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            if (cir[i][j] > 0)
                average += cir[i][j], cnt++;

    if (cnt == 0) return;

    average /= cnt;
    Refresh_cir(average);
}

void Refresh_cir(double average)
{
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
        {
            if (cir[i][j] == 0) continue;
            if ((double)cir[i][j] > average) cir[i][j]--;
            else if ((double)cir[i][j] < average) cir[i][j]++;
        }
}

void Answer()
{
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            answer += cir[i][j];
}
