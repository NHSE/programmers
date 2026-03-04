#include <string>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;

    for (long long i = l; i <= r ; i++){
        int flag = 1;
        if (i % 5 == 3){
            continue;
        }
        long long temp = i;
        long long result;
        while (1){
            if (temp % 5 == 0){
                temp = temp / 5;
            }
            else {
                temp = (temp / 5) + 1;
            }

            if (temp % 5 == 3){
                flag = 0;
                break;
            }
            else if (temp <= 5){
                flag = 1;
                break;
            }
        }

        if (flag == 1) answer++;
    }

    return answer;
}