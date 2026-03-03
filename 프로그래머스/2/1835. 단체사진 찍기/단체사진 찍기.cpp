#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<bool> ch; // DFS에서 해당 원소를 사용했는가
vector<int> sel; // n번째에서 몇번 값을 사용하는가
string characters; // 캐릭터 배열
int cnt; // 사용할 개수 (캐릭터는 8개)
int answer; // 정답 누적

bool checkValid(vector<string>& data, map<char, int>& m)
{
    for(string s : data)
    {
        // 두 캐릭터 사이의 간격
        int dist = abs(m[s[0]] - m[s[2]]) - 1;

        // 요구 숫자
        int num = s[4] - '0';

        // 요구 조건
        switch(s[3])
        {
            case '=': // 간격이 같은경우?
            {
                // 간격이 다르면 false
                if(dist != num)
                    return false;
                break;
            }
            case '<': // 간격이 미만?
            {
                // 간격이 이상이면 false
                if(dist >= num)
                    return false;
                break;
            }
            case '>': // 간격이 초과?
            {
                // 간격이 이하이면 false
                if(dist <= num)
                    return false;                
                break;
            }                
        }
    }

    return true;
}

void DFS(int n, vector<string>& data)
{
    // 모두 선택했다면?
    if(n == cnt)
    {
        // map에 해당 캐릭터의 위치를 저장
        map<char, int> m;
        for(int i = 0; i < cnt; ++i)
            m[characters[sel[i]]] = i;

        // 해당 캐릭터 조합이 data 조건을 모두 만족한다면, ++answer;
        if(checkValid(data, m))
            ++answer;
    }
    else
    {
        for(int i = 0; i < cnt; ++i)
        {
            if(!ch[i])
            {
                sel[n] = i;
                ch[i] = true;
                DFS(n + 1, data);
                ch[i] = false;
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {

    characters = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    ch = vector<bool>(8, false);
    sel = vector<int>(8, -1);
    answer = 0;
    cnt = 8;
    DFS(0, data);

    return answer;
}