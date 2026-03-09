#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<bool> visited = {false, };
vector<int> result;

int N, M;

void BFS(int node);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    v.resize(N+1);
    visited.resize(N+1, false);
    result.resize(N+1, 0);

    for(int i=1; i<M+1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for(int i=1; i<N+1; i++)
    {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int max_ = *max_element(result.begin(), result.end());

    for(int i=1; i<N+1; i++)
    {
        if(result[i] == max_)
        {
            cout << i << " ";
        }
    }
}

void BFS(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty())
    {
        int temp = q.front();

        q.pop();

        for(auto i : v[temp])
        {
            if(!visited[i])
            {
                visited[i] = true;
                result[i] += 1;
                q.push(i);
            }
        }
    }
}