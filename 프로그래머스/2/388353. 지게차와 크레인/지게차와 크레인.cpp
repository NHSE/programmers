#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Data
{
    int r, c;  
};

#define MAX 52

char Map[MAX][MAX];
bool OutMap[MAX][MAX] = {false, };
int N, M;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void debug()
{
    for(int r=0; r<=N+1; r++)
    {
        for(int c=0; c<=M+1; c++)
        {
            cout << Map[r][c] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    for(int r=0; r<=N+1; r++)
    {
        for(int c=0; c<=M+1; c++)
        {
            cout << OutMap[r][c] << " ";
        }
        cout << endl;
    }
}

void Init()
{
    for(int r=0; r<MAX; r++)
    {
        for(int c=0; c<MAX; c++)
        {
            Map[r][c] = '0';
        }
    }
    
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            OutMap[r][c] = true;
        }
    }
}

bool IsRange(int r, int c)
{
    return r >= 0 && r <= N+1 && c >= 0 && c <= M+1;
}


vector<Data> BFS(int r, int c)
{
    vector<Data> ret;
    queue<Data> q;
    q.push({r, c});
    
    bool visited[MAX][MAX] = {false, };
    visited[r][c] = true;
    
    while(!q.empty())
    {
        Data data = q.front();
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nr = data.r + dr[i];
            int nc = data.c + dc[i];
            
            if(!IsRange(nr, nc))    continue;
            
            if(!visited[nr][nc])
            {
                if(Map[nr][nc] == '0')
                {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                    
                    if(OutMap[nr][nc])
                        OutMap[nr][nc] = false;
                }
            }
        }
    }
    
    return ret;
}


void Remove_Map(char word)
{
    vector<Data> remove;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            if(Map[r][c] == word)
            {
                for(int i=0; i<4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if(!OutMap[nr][nc])
                    {
                        remove.push_back({r,c});
                        break;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<remove.size(); i++)
    {
        Data data = remove[i];
        Map[data.r][data.c] = '0';
        OutMap[data.r][data.c] = false;
        BFS(data.r, data.c);
    }
}

void Remove_AllMap(char word)
{
    vector<Data> remove;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            if(Map[r][c] == word)
            {
                Map[r][c] = '0';
                
                for(int i=0; i<4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if(!OutMap[nr][nc])
                    {
                        OutMap[r][c] = false;
                        BFS(r, c);
                        break;
                    }
                }
            }
        }
    }
}

int Check_Map()
{
    int ret = 0;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            if(Map[r][c] != '0')    ret++;
        }
    }
    
    return ret;
}

int solution(vector<string> storage, vector<string> requests) {
 
    N = storage.size(), M = storage[0].size();
    Init();
    
    for(int r=0; r<storage.size(); r++)
    {
        for(int c=0; c<storage[r].size(); c++)
        {
            Map[r+1][c+1] = storage[r][c];
        }
    }
    
    //debug();
    //cout << endl;
    
    for(int i=0; i<requests.size(); i++)
    {
        char word;
        if(requests[i].size() > 1) // 2개 이상
        {
            word = requests[i][0];
            Remove_AllMap(word);
        }
        else // 1개
        {
            word = requests[i][0];
            Remove_Map(word);
        }
        
        //debug();
        //cout << endl;
    }
    
    //debug();
    
    int answer = Check_Map();
    return answer;
}