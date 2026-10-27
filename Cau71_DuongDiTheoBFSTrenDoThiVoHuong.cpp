#include <bits/stdc++.h>

using namespace std;

void solve() {
    int v, e, s, t;
    if (!(cin >> v >> e >> s >> t)) return;
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
    vector<int> parent(v + 1, -1);
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    
    bool found = false;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr == t) {
            found = true;
            break;
        }
        
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }
    
    if (!found) {
        cout << -1 << "\n";
    } else {
        vector<int> path;
        int curr = t;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    if (cin >> test) {
        while (test--) {
            solve();
        }
    }
    return 0;
}