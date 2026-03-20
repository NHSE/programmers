#include <string>
#include <vector>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1 ,1};

int rsize = 0, csize = 0;

bool IsRange(int r, int c)
{
    return r >= 0 && r < rsize && c >= 0 && c < csize;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    rsize = board.size();
    csize = board[0].size();
    
    string color = board[h][w];
    for(int i=0; i<4; i++)
    {
        int nr = h + dr[i];
        int nc = w + dc[i];
        
        if(!IsRange(nr, nc))    continue;
        if(board[nr][nc] == color)
        {
            answer++;
        }
    }
    return answer;
}