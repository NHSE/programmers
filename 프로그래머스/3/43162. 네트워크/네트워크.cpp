#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool connect[201][201] = {false, };
bool visited[201] = {false, };
int N;

void BFS(int num)
{
    queue<int> q;
    q.push(num);
    
    visited[num] = true;
    
    while(!q.empty())
    {
        int data = q.front();
        q.pop();
        
        for(int i=0; i<N; i++)
        {
            if(data == i)   continue;
            if(!visited[i])
            {
                if(connect[data][i] || connect[i][data])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    
    for(int i=0; i<computers.size(); i++)
    {
        vector<int> list;
        for(int j=0; j<computers.size(); j++)
        {
            if(computers[i][j] == 1)    list.push_back(j);
        }
        
        for(int a=0; a<list.size(); a++)
        {
            for(int b=0; b<list.size(); b++)
            {
                if(a == b)  continue;
                
                connect[list[a]][list[b]] = true;
                //cout << list[a] << " " << list[b] << endl;
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            BFS(i);
            //cout << i << endl;
            answer++;
        }
    }
    return answer;
}