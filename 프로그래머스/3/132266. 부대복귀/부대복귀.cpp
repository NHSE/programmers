#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

vector<vector<int>> v;

struct Data
{
    int index, depth;  
};

int BFS(int start, int destination)
{
    queue<Data> q;
    q.push({start, 0});
    bool visited[MAX] = {false, };
    
    while(!q.empty())
    {
        Data data = q.front();
        q.pop();
        
        if(data.index == destination)
        {
            //cout << data.depth << endl;
            return data.depth;
        }
        
        for(int i=0; i<v[data.index].size(); i++)
        {
            int value = v[data.index][i];
            if(!visited[value])
            {
                visited[value] = true;
                q.push({value, data.depth + 1});
            }
        }
    }

    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    v.resize(n+1);
    
    for(int i=0; i<roads.size(); i++)
    {
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0; i<sources.size(); i++)
    {
        int start = sources[i];
        answer.push_back(BFS(start, destination));
    }
    return answer;
}