#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    for(int h = 1000; h > 0; h--){
        int num = 0;
        for(int i = 0; i < citations.size(); i++){
            if (citations[i] >= h) num++;
        }
        if (num >= h) return h;
    }
}