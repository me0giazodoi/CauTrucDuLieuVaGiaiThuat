#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, n;
    if (!(cin >> m >> n)) return;
    vector<vector<int>> a(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{1, 1}, 0});
    visited[1][1] = true;
    
    while (!q.empty()) {
        auto [pos, steps] = q.front();
        q.pop();
        int r = pos.first;
        int c = pos.second;
        
        if (r == m && c == n) {
            cout << steps << "\n";
            return;
        }
        
        int val = a[r][c];
        
        int next_c = c + val;
        if (next_c <= n && !visited[r][next_c]) {
            visited[r][next_c] = true;
            q.push({{r, next_c}, steps + 1});
        }
        
        int next_r = r + val;
        if (next_r <= m && !visited[next_r][c]) {
            visited[next_r][c] = true;
            q.push({{next_r, c}, steps + 1});
        }
    }
    
    cout << -1 << "\n";
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