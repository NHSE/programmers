#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;

    for(int i=3; i<=area; ++i)
    {
        if(area%i == 0)
        {
            int num = area/i;

            if((i-2) *(num-2) == yellow)
            {
                answer.push_back(num);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}