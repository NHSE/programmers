#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Data
{
    int tangerine, cnt;
};

bool cmp(Data A, Data B)
{
    if(A.cnt != B.cnt)
        return A.cnt > B.cnt;
    else
        return A.tangerine < B.tangerine;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<Data> v;
    unordered_map<int, int> m;
    
    for(int i=0; i<tangerine.size(); i++)
    {
        m[tangerine[i]]++;
    }
    
    for(auto it : m)
    {
        v.push_back({it.first, it.second});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int prev = -1;
    int start = 0;
    while(1)
    {
        int next = v[start].tangerine;
        int cnt = v[start].cnt;
        
        if(prev != next)
        {
            k -= cnt;
            answer++;
            
            prev = next;
            start++;
        }
        
        if(k <= 0)  break;
    }
    return answer;
}