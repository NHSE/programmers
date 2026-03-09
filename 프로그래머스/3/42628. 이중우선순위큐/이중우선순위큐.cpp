#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

deque<int> q;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i=0; i<operations.size(); i++)
    {
        string cmd = operations[i];

        if(cmd == "D -1")
        {
            if(q.empty())   continue;
            
            q.pop_front();
        }
        else if(cmd == "D 1")
        {
            if(q.empty())   continue;
            
            q.pop_back();
        }
        else
        {
            int value = stoi(cmd.substr(2));
            q.push_back(value);
        }
        
        if(!q.empty())
        {
            //정렬
            vector<int> v;
            while(!q.empty())
            {
                v.push_back(q.front());
                q.pop_front();
            }
            sort(v.begin(), v.end());
            
            q.clear();

            for(int j=0; j<v.size(); j++)
            {
                //cout << v[j] << endl;
                q.push_back(v[j]);
            }   
            //q = v;
        }
        //cout << "---" << endl;
    }
    
    if(!q.empty())
    {
        answer.push_back(q.back());
        answer.push_back(q.front());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}