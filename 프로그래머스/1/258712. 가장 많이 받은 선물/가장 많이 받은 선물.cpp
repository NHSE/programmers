#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int max_ = 0;
    unordered_map<string, unordered_map<string, int>> m;
    unordered_map<string, int> m1; // 준 횟수
    unordered_map<string, int> m2; // 받은 횟수
    unordered_map<string, int> m3;
    unordered_map<string, int> m4;
    
    for(auto& it : friends)
    {
        for(auto& it2 : friends)
        {
            if(it != it2) m[it][it2] = 0;
        }
        m1[it];
        m2[it];
        m3[it];
    }
    
    for(auto& gift : gifts)
    {
        stringstream in(gift);
        string a, b; in >> a >> b;
        m[a][b];
        m[a][b]++;
        m1[a]++;
        m2[b]++;
    }
    for(const auto& name : friends)
    {
        m3[name] = m1[name] - m2[name];  // 선물 지수
    }
    
    for(const auto& name : friends)
    {
        for(auto& send : m[name])
        {
            if(send.second > m[send.first][name]) // 준 선물이 받은 선물보다 많을때
            {
                m4[name]++; //muzi ++
                max_ = max(m4[name], max_);
            }
            if(send.second == m[send.first][name]) //준 선물 받은 선물 똑같을 때
            {
                if(m3[name] > m3[send.first]) // 선물지수 비교
                {
                    m4[name]++;
                    max_ = max(m4[name], max_);
                }
            }
        }
    }
    answer = max_;
    return answer;
}