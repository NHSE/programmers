#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Data
{
    int num;
    float persent;
};

bool cmp(Data A, Data B)
{
    if(A.persent != B.persent)  return A.persent > B.persent;
    else                        return A.num < B.num;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stage(N+2, 0);
    for(int i=0; i<stages.size(); i++)
    {
        stage[stages[i]]++;
    }
    
    int total_people = stages.size();
    vector<Data> v(N+1, {0, 0.0});
    
    for(int i=1; i<=N; i++)
    {
        int people = stage[i];
        float persent = 0;
        if(total_people > 0)
            persent = (float)people / (float)total_people;
        cout << people << "/" << total_people << endl;
        total_people -= people;
        v[i] = {i, persent};
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<=N; i++)
    {
        if(v[i].num == 0)   continue;
        cout << i << " " << v[i].num << " " << v[i].persent << endl;
        answer.push_back(v[i].num);
    }
    return answer;
}