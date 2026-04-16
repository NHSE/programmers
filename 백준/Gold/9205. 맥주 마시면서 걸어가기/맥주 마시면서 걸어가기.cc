#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int t, n;
vector<pair<int, int>> stores;
bool visited[100];

bool bfs(int start_x, int start_y, int end_x, int end_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 목적지에 도착 가능하면 happy
        if (abs(x - end_x) + abs(y - end_y) <= 1000) return true;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int store_x = stores[i].first;
                int store_y = stores[i].second;

                if (abs(x - store_x) + abs(y - store_y) <= 1000) {
                    visited[i] = true;
                    q.push({store_x, store_y});
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        stores.clear();
        fill(visited, visited + n, false);

        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            stores.push_back({x, y});
        }
        cin >> end_x >> end_y;

        if (bfs(start_x, start_y, end_x, end_y)) 
            cout << "happy\n";
        else 
            cout << "sad\n";
    }
}
