#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, int& timer, vector<pair<int, int>>& bridges) {
    tin[u] = low[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u, adj, tin, low, timer, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                int a = min(u, v);
                int b = max(u, v);
                bridges.push_back({a, b});
            }
        }
    }
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
    
    vector<int> tin(v + 1, 0);
    vector<int> low(v + 1, 0);
    int timer = 0;
    vector<pair<int, int>> bridges;
    
    for (int i = 1; i <= v; i++) {
        if (!tin[i]) {
            dfs(i, -1, adj, tin, low, timer, bridges);
        }
    }
    
    sort(bridges.begin(), bridges.end());
    
    for (size_t i = 0; i < bridges.size(); i++) {
        cout << bridges[i].first << " " << bridges[i].second << (i == bridges.size() - 1 ? "" : " ");
    }
    cout << "\n";
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