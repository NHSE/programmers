#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

struct Data
{
    int time;  
};

deque<Data> server;

void debug()
{
    deque<Data> tmp;
    tmp = server;
    
    while(!tmp.empty())
    {
        Data data = tmp.front();
        tmp.pop_front();
        
        cout << data.time << " ";
    }
    cout << endl;
}

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for(int i=0; i<players.size(); i++)
    {
        while(server.size() > 0)
        {
            Data data = server.front();
            
            if(i == data.time)  server.pop_front();
            else                break;
        }
        
        int value = players[i] / m;
        if(value > server.size())
        {
            answer += value - server.size();
            cout << "--" << value - server.size() << endl;
            int size = value - server.size();
            for(int j=0; j<size; j++)
            {
                server.push_back({i + k});
            }
        }
        
        cout << i << " ";
        debug();
    }
    return answer;
}