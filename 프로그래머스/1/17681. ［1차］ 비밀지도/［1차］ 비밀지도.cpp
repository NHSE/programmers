#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer; // 최종 결과를 담을 문자열 벡터
    
    for(int i = 0; i < n; i++) // 각 행마다 처리
    {
        string row = ""; // 현재 행의 결과를 저장할 문자열
        int line = arr1[i] | arr2[i]; // 두 지도에서 OR 연산 수행 (벽이 하나라도 있으면 벽)

        for(int j = 0; j < n; j++) // 오른쪽부터 한 비트씩 확인
        {
            // 맨 끝 비트를 확인하여 1이면 벽, 0이면 공백을 추가
            row = ((line & 1) ? "#" : " ") + row;
            line = line >> 1; // 다음 비트를 보기 위해 오른쪽으로 쉬프트
        }

        answer.push_back(row); // 완성된 한 줄을 결과 벡터에 추가
    }
    
    return answer; // 최종 지도 반환
}