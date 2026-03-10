#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lost_ptr = 0, reserve_ptr = 0, student = 0;
    vector<int> lost_;
    vector<int> reserve_;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(auto& it : reserve)
    {
        cout << it << endl;
        auto it1 = find(lost.begin(), lost.end(), it);
        if(it1 == lost.end())
        {
            reserve_.push_back(it);
        }
        else
        {
            lost.erase(it1);
        }
    }

    for(int i=0; i < n; i++)
    {
        if(lost_ptr < lost.size() && reserve_ptr < reserve_.size())
        {
            //cout << reserve[reserve_ptr] << " " << lost[lost_ptr] << endl;
            if(reserve_[reserve_ptr] - lost[lost_ptr] == 1 ||
            reserve_[reserve_ptr] - lost[lost_ptr] == -1)
            {
                student++;
                lost_ptr++;
                reserve_ptr++;
            }
            else if(reserve_[reserve_ptr] - lost[lost_ptr] > 1)
            {
                lost_ptr++;
            }
            else if(lost[lost_ptr] - reserve_[reserve_ptr] > 1)
            {
                reserve_ptr++;
            }
            else if(reserve_[reserve_ptr] == lost[lost_ptr])
            {
                student++;
                lost_ptr++;
                reserve_ptr++;
            }
        }
        else
            continue;
    }
    answer = (n-lost.size()) + student;
    return answer;
}