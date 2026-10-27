#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, int p, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) return true;
        if (dfs(v, u, adj, visited)) return true;
    }
    return false;
}

void solve() {
    int v, e;
    if (!(cin >> v >> e)) return;
    vector<vector<int>> adj(v + 1);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool> visited(v + 1, false);
    bool has_cycle = false;
    
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                has_cycle = true;
                break;
            }
        }
    }
    
    if (has_cycle) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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