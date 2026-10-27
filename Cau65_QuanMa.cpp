#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, e;
    if (!(cin >> s >> e)) return;
    
    int start_x = s[0] - 'a' + 1;
    int start_y = s[1] - '0';
    int end_x = e[0] - 'a' + 1;
    int end_y = e[1] - '0';
    
    if (start_x == end_x && start_y == end_y) {
        cout << 0 << "\n";
        return;
    }
    
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(9, vector<bool>(9, false));
    
    q.push({{start_x, start_y}, 0});
    visited[start_x][start_y] = true;
    
    while (!q.empty()) {
        auto [pos, steps] = q.front();
        q.pop();
        int x = pos.first;
        int y = pos.second;
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx == end_x && ny == end_y) {
                cout << steps + 1 << "\n";
                return;
            }
            
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}