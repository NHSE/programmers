#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
    int f, s;
    bool fail = false;
};

vector<Data> v;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    for(int i=0; i<scores.size(); i++)
    {
        int f = scores[i][0];
        int s = scores[i][1];
        v.push_back({f, s});
    }
    
    int wanho_f = v[0].f;
    int wanho_s = v[0].s;

    // 🔥 핵심 정렬
    sort(v.begin(), v.end(), [](Data &a, Data &b){
        if(a.f == b.f)
            return a.s < b.s;  // f 같으면 s 오름차순
        return a.f > b.f;      // f 내림차순
    });

    int max_s = 0;

    for(int i=0; i<v.size(); i++)
    {
        if(v[i].s < max_s)
        {
            v[i].fail = true;
        }
        else
        {
            max_s = v[i].s;
        }
    }

    // 완호가 탈락이면 -1
    for(auto &d : v)
    {
        if(d.f == wanho_f && d.s == wanho_s)
        {
            if(d.fail) return -1;
            break;
        }
    }

    int wanho_sum = wanho_f + wanho_s;
    answer = 1;

    for(int i=0; i<v.size(); i++)
    {
        if(v[i].fail) continue;

        if(v[i].f + v[i].s > wanho_sum)
            answer++;
    }

    return answer;
}