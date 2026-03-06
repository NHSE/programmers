#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int index = 0;
    while(index != prices.size())
    {
        int price = prices[index];
        int time = 0;
        for(int i=index+1; i<prices.size(); i++)
        {
            time++;
            if(price > prices[i])
            {
                break;
            }
        }
        
        answer.push_back(time);
        index++;
    }
    return answer;
}