#include <iostream>
#include <vector>
using namespace std;


int dp[100001][4];
int sum = 0;

int solution(vector<vector<int>> land) {
    int answer = 0;


    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    int sum = dp[i - 1][j] + land[i][k];
                    if (dp[i][k] < sum) dp[i][k] = sum;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (dp[land.size() - 1][i] > answer) answer = dp[land.size() - 1][i];
    }
    return answer;
}