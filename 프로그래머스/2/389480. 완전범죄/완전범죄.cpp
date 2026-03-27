#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> B_list;
vector<vector<int>> list;

int N, M;

int answer = 1e9;

bool visited[41][121][121] = {false, };

void DFS(int A, int B, int next, int depth)
{
    //cout << "A : " << A << " B : " << B << endl;
    
    if(A >= N || B >= M)    return;
    
    if(visited[next][B][A]) return;
    visited[next][B][A] = true;
    
    if(depth == list.size())
    {
        //cout << "-A : " << A << " B : " << B << endl;
        answer = min(A, answer);
        return;
    }
    
    //cout << "A " << next << " " << A << " + " << list[next][0] << endl;
    DFS(A + list[next][0], B, next+1, depth+1);
    //cout << "B " << next << " " << B << " + " << list[next][1] << endl;
    DFS(A, B + list[next][1], next+1, depth+1);
}

int solution(vector<vector<int>> info, int n, int m) {
    list = info;
    N = n, M = m;

    DFS(0, 0, 0, 0);
    
    
    if(answer == 1e9)   answer = -1;

    return answer;
}