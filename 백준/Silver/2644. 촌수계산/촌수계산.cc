#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
vector<int> answer;

int N, M;
int a, b;

int count = 0;

void DFS(int z, int cnt);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> a >> b;
    cin >> M;

    v.resize(N+1);
    visited.resize(N+1, false);
    
    for(int i=0; i<M; i++)
    {
        int tempa, tempb;
        cin >> tempa >> tempb;
        v[tempa].push_back(tempb);
        v[tempb].push_back(tempa);
    }

    DFS(a, 0);
    //DFS(b, 0);
    
    if(count > 0)
        cout << count;
    else
        cout << "-1";
}

void DFS(int z, int cnt)
{
    //cout << z << " " << cnt << endl;
    if(visited[z])
        return;
    if(z == b)
    {
        count += cnt;
    }
    visited[z] = true;

    for(int i : v[z])
    {
        if(!visited[i])
        {
            DFS(i, cnt+1);
        }
    }
}