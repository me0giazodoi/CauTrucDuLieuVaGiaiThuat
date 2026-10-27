#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<bool>& is_cut, int& timer) {
    tin[u] = low[u] = ++timer;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u, adj, tin, low, is_cut, timer);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1) {
                is_cut[u] = true;
            }
            children++;
        }
    }
    if (p == -1 && children > 1) {
        is_cut[u] = true;
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
    vector<bool> is_cut(v + 1, false);
    int timer = 0;
    
    for (int i = 1; i <= v; i++) {
        if (!tin[i]) {
            dfs(i, -1, adj, tin, low, is_cut, timer);
        }
    }
    
    for (int i = 1; i <= v; i++) {
        if (is_cut[i]) {
            cout << i << " ";
        }
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