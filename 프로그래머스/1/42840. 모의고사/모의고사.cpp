#include <string>
#include <vector>
#include <iostream>

using namespace std;

int first_people[] = {1, 2, 3, 4, 5};
int second_people[] = {2, 1, 2, 3, 2, 4, 2, 5};
int third_people[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int first_Correct = 0;
int second_Correct = 0;
int third_Correct = 0;

vector<int> Answer()
{
    if(first_Correct == second_Correct && second_Correct == third_Correct)
    {
        return {1, 2, 3};
    }
    
    int max_Correct = max(first_Correct, second_Correct);
    max_Correct = max(max_Correct, third_Correct);
    
    vector<int> ret;
    
    if(max_Correct == first_Correct)    ret.push_back(1);
        
    if(max_Correct == second_Correct)   ret.push_back(2);
        
    if(max_Correct == third_Correct)    ret.push_back(3);
    
    return ret;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == first_people[i % 5])
        {
            first_Correct++;
        }
        
        if(answers[i] == second_people[i % 8])
        {
            second_Correct++;
        }
        
        if(answers[i] == third_people[i % 10])
        {
            third_Correct++;
        }
    }
    
    answer = Answer();
    
    cout << first_Correct << " " << second_Correct << " " << third_Correct;
    return answer;
}