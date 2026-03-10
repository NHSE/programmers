#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> number;
int t = 0;
int ret = 0;

void DFS(vector<int> list, int num, int index)
{
    if(index == number.size())
    {        
        if(num == t)
        {
            ret++;
        }
        return;
    }
    
    // +
    num += number[index];
    list.push_back(number[index]);
    index++;
    
    DFS(list, num, index);
    num -= number[--index];
    list.pop_back();
    
    // -
    num -= number[index];
    list.push_back(-number[index]);
    index++;
    DFS(list, num, index);
    num += number[--index];
    list.pop_back();
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    number = numbers;
    t = target;
    
    vector<int> list;
    list.push_back(numbers[0]);
    DFS(list, numbers[0], 1);
    
    list.clear();
    list.push_back(-numbers[0]);
    DFS(list, -numbers[0], 1);
    return ret;
}