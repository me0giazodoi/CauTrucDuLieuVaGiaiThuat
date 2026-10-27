#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    dist[0][0] = a[0][0];
    pq.push({a[0][0], {0, 0}});
    
    while (!pq.empty()) {
        auto [d, pos] = pq.top();
        pq.pop();
        int r = pos.first;
        int c = pos.second;
        
        if (d > dist[r][c]) continue;
        if (r == n - 1 && c == m - 1) {
            cout << d << "\n";
            return;
        }
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (dist[r][c] + a[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + a[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
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