#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> v
    {
        781, 156, 31, 6, 1
    };

    map<char, int> m
    {
        make_pair('A', 1),
        make_pair('E', 2),
        make_pair('I', 3),
        make_pair('O', 4),
        make_pair('U', 5),
    };

    for(int i = 0; i < word.size(); i++)
    {
        answer += (m[word[i]] - 1) * v[i] + 1;
    }

    return answer;
}