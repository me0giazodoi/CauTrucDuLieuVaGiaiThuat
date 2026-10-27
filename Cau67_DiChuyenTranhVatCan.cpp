#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    if (x1 == x2 && y1 == y2) {
        cout << 0 << "\n";
        return;
    }
    
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    
    q.push({{x1, y1}, 0});
    dist[x1][y1] = 0;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        auto [pos, steps] = q.front();
        q.pop();
        int r = pos.first;
        int c = pos.second;
        
        if (r == x2 && c == y2) {
            cout << steps << "\n";
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            
            while (nr >= 0 && nr < n && nc >= 0 && nc < n && a[nr][nc] != 'X') {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = steps + 1;
                    q.push({{nr, nc}, steps + 1});
                } else if (dist[nr][nc] < steps + 1) {
                    break;
                }
                nr += dx[i];
                nc += dy[i];
            }
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