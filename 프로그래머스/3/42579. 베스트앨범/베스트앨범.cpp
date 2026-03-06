#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

bool cmp_1(pair<int, int> &a, pair<int, int> &b)
{
    if(a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

bool cmp_2(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> m;
    map<string, int>  cnt;
    
    for(int i=0; i<genres.size(); i++)
    {
        m[genres[i]].push_back(make_pair(i, plays[i]));
        cnt[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> list(cnt.begin(), cnt.end());
    sort(list.begin(), list.end(), cmp_2);
    
    /*for(int i=0; i<list.size(); i++)
    {
        cout << list[i].first << " " << list[i].second << endl;
    }*/
    
    for(auto &it : m)
    {
        sort(it.second.begin(), it.second.end(), cmp);
    }
    
    for(int i=0; i<list.size(); i++)
    {
        int count = 0;
        for(int j=0; j<m[list[i].first].size(); j++)
        {
            //cout << m[list[i].first][j].first << " " << m[list[i].first][j].second << endl;
            answer.push_back(m[list[i].first][j].first);
            count++;
            
            if(count == 2)
            {
                break;
            }
        }
    }

    return answer;
}