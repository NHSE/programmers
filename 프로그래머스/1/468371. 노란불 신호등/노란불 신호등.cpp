#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define GREEN 0
#define YELLOW 1
#define RED 2

int solution(vector<vector<int>> signals) {
    int answer = 1;
    vector<int> time(signals.size(), 0);
    vector<int> color(signals.size(), 0);
    
    while(1)
    {
        // 종료 조건 먼저 체크
        bool flag = true;
        for(int i=0; i<signals.size(); i++)
        {
            if(color[i] != YELLOW)
            {
                flag = false;
                break;
            }
        }
        if(flag) break;

        // 시간 진행
        for(int i=0; i<signals.size(); i++)
        {
            time[i]++;

            if(time[i] == signals[i][color[i]])
            {
                time[i] = 0;
                color[i] = (color[i] + 1) % 3;
            }
        }
        
        answer++;

        if(answer > 100000000)
            return -1;
    }

    return answer;
}