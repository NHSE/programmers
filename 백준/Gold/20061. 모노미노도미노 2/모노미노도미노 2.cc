#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
// #include <map>
#include <unordered_map>
#define ll long long
#define INF 1e9
using namespace std;

int ans = 0;
int n;
int bd[10][10];
int blocks = 0;
int t,x,y;

void moveBlock() {
	int i,j;
	if(t==1) {  // 1x1
		// green
		i = x;
		while(i<9 && !bd[i+1][y]) {
			i++;
		}
		// blue
		j = y;
		while(j<9 && !bd[x][j+1]) {
			j++;
		}
	} else if(t==2) {  // 1x2
		// green
		i = x;
		while(i<9 && !bd[i+1][y] && !bd[i+1][y+1]) {
			i++;
		}
		// blue
		j = y+1;
		while(j<9 && !bd[x][j+1]) {
			j++;
		}
	} else if(t==3) {
		// green
		i = x+1;
		while(i<9 && !bd[i+1][y]) {
			i++;
		}
		// blue
		j = y;
		while(j<9 && !bd[x][j+1] && !bd[x+1][j+1]) {
			j++;
		}
	}

	if(t==1) {
		bd[i][y] = 1;
		bd[x][j] = 1;
	} else if(t==2) {
		bd[i][y] = 1; bd[i][y+1] = 1;
		bd[x][j] = 1; bd[x][j-1] = 1;
	} else if(t==3) {
		bd[i-1][y] = 1; bd[i][y] = 1;
		bd[x][j] = 1; bd[x+1][j] = 1;
	}
	
	return;	
}

void removeAnyFilledRowOrCol() {
	// green rows
	int start = -1;
	int removed = 0;
	for(int i=6;i<10;++i) {
		for(int j=0;j<4;++j) {
			if(!bd[i][j]) break;  // not a filled row

			if(j==3) {
				start = max(start, i);
				removed++;
			}
		}
	}

	if(start > -1) {
		for(int i=start-removed;i>=4;--i) {
			for(int j=0;j<4;++j) {
				bd[i+removed][j] = bd[i][j];
				bd[i][j] = 0;
			}
		}


		ans += removed;
	}

	// blue cols
	start = -1;
	removed = 0;
	for(int j=6;j<10;++j) {
		for(int i=0;i<4;++i) {
			if(!bd[i][j]) break; // not a filled col

			if(i==3) {
				start = max(start,j);
				removed++;
			}
		}
	}

	if(start > -1) {
		for(int j=start-removed;j>=4;--j) {
			for(int i=0;i<4;++i) {
				bd[i][j+removed] = bd[i][j];
				bd[i][j] = 0;
			}
		}

		ans += removed;
	}

	return;
}

void blocksInSpecialArea() {
	// green
	int rows = 0;
	for(int i=4;i<=5;++i) {
		for(int j=0;j<4;++j) {
			if(bd[i][j]) {
				rows++;
				break;
			}
		}
	}

	if(rows > 0) {
		for(int i=9-rows;i>=4;--i) {
			for(int j=0;j<4;++j) {
				bd[i+rows][j] = bd[i][j];
			}
		}
		for(int i=4;i<=5;++i) {
			for(int j=0;j<4;++j) {
				bd[i][j] = 0;
			}
		}
	}

	// blue
	int cols = 0;
	for(int j=4;j<=5;++j) {
		for(int i=0;i<4;++i) {
			if(bd[i][j]) {
				cols++;
				break;
			}
		}
	}

	if(cols > 0) {
		for(int j=9-cols;j>=4;--j) {
			for(int i=0;i<4;++i) {
				bd[i][j+cols] = bd[i][j];
			}
		}
		for(int j=4;j<=5;++j) {
			for(int i=0;i<4;++i) {
				bd[i][j] = 0;
			}
		}
	}
}

void sol() {
	moveBlock();
	removeAnyFilledRowOrCol();
	blocksInSpecialArea();
}

int main(void) {
	// ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	scanf("%d", &n);
	for(int i=0;i<n;++i) {
		scanf("%d%d%d", &t,&x,&y);

		sol();
	}

	for(int i=0;i<4;++i) {
		for(int j=6;j<10;++j) {
			if(bd[i][j]) {
				blocks++;
			}
		}
	}

	for(int i=6;i<10;++i) {
		for(int j=0;j<4;++j) {
			if(bd[i][j]) {
				blocks++;
			}
		}
	}
	

	printf("%d\n", ans);
	printf("%d\n", blocks);
	
	return 0;
}