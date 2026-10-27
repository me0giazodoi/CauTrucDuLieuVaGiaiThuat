#include <bits/stdc++.h>

using namespace std;

void solve() {
    int v, e, u;
    if (!(cin >> v >> e >> u)) return;
    vector<vector<int>> adj(v + 1);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 1; i <= v; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    vector<bool> visited(v + 1, false);
    queue<int> q;
    
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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