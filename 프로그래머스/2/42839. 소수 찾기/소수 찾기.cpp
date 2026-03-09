#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool visited[10] = {false, };
vector<int> v;
vector<int> list;
unordered_map <int, int> m;

bool Check_Number(int value)
{
    if(value < 2)  return false;
    
    for(int i=2; i<value; i++)
    {
        if(value % i == 0)  return false;
    }
    
    return true;
}

void DFS(string &s)
{
    if(m.find(stoi(s)) == m.end())
    {
        list.push_back(stoi(s));
        m[stoi(s)] = 1;
    }
    
    for(int i=0; i<v.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            s += to_string(v[i]);
            
            DFS(s);
            
            visited[i] = false;
            s.pop_back();
        }
    }
}

int solution(string numbers) {
    
    int answer = 0;
    
    for(int i=0; i<numbers.size(); i++)
    {
        v.push_back(numbers[i] - '0');
    }
    
    for(int i=0; i<v.size(); i++)
    {
        visited[i] = true;
        
        string s = to_string(v[i]);
        DFS(s);
        
        visited[i] = false;
    }
    
    for(int i=0; i<list.size(); i++)
    {
        if(Check_Number(list[i]))   
        {
            cout << list[i] << endl;
            answer++;
        }
    }
    return answer;
}