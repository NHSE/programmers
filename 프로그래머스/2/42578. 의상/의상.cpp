#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int>m;
    for(int i=0; i<clothes.size(); i++)
    {
        m[clothes[i][1]]++;
    }
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        answer *= (it->second+1);
        //cout << answer << endl;
    }
    cout << m.size() << endl;
    //if(m.size() > 1)
        //answer = answer + (count-1);
    return answer-1;
}