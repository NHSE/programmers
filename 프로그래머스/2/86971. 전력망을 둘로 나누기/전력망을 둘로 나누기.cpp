#include <bits/stdc++.h>

using namespace std;

int BFS(vector<int> graphs[], int n){
    int count = 0;
    bool visits[101] = {false, };
    queue<int> q;
    q.push(n);
    visits[n] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(auto nxt : graphs[current]){
            if(visits[nxt]) continue;
            q.push(nxt);
            visits[nxt] = true;
            count++;
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 105;

    int sizes = wires.size();
    for(int n = 0; n < sizes; n++){
        vector<int> v[105];
        int n1, n2;
        int count1, count2;
        // 그래프 만들기 (문제에 맞게 설계)
        for(int i = 0; i < sizes; i++){
            if(n == i) {
                n1 = wires[n][0];
                n2 = wires[n][1];
                continue;
            }
            v[wires[i][0]].push_back(wires[i][1]);
            v[wires[i][1]].push_back(wires[i][0]);
        }
        count1 = BFS(v, n1);
        count2 = BFS(v, n2);
        if(answer > abs(count1 - count2)) answer = abs(count1 - count2);
    }

    return answer;
}