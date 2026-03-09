#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int K;
bool visited[10] = {false, };
vector<vector<int>> v;

int ret = 0;

void DFS(int k, int num, int depth)
{   
    //cout << num << endl;
    if(depth > ret) ret = depth;
    
    if(k == 0 || depth == v.size())
    {
        //cout << "--" << depth << endl;
        return;
    }
    
    for(int i=0; i<v.size(); i++)
    {
        if(!visited[i])
        {
            if(k >= v[i][0])
            {
                visited[i] = true;
                k -= v[i][1];
                DFS(k, i, depth + 1);
                visited[i] = false;
                k += v[i][1];
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    K = k;
    v = dungeons;
    
    for(int i=0; i<dungeons.size(); i++)
    {
        if(K < dungeons[i][0])  continue;
        
        visited[i] = true;
        int value = K - dungeons[i][1];
        DFS(value, i, 1);
        visited[i] = false;
    }
    
    //cout << ret << endl;
    return ret;
}