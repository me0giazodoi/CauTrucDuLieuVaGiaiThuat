#include <bits/stdc++.h>

using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<pair<int, int>>& tree_edges) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree_edges.push_back({u, v});
            dfs(v, adj, visited, tree_edges);
        }
    }
}

void solve() {
    int n, m, u;
    if (!(cin >> n >> m >> u)) return;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> tree_edges;
    
    dfs(u, adj, visited, tree_edges);
    
    if (tree_edges.size() != n - 1) {
        cout << -1 << "\n";
    } else {
        for (auto& edge : tree_edges) {
            cout << edge.first << " " << edge.second << "\n";
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