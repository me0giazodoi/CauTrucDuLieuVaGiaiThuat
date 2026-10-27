#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int v_cnt, e_cnt, start_u;
    if (!(cin >> v_cnt >> e_cnt >> start_u)) return;
    vector<vector<pair<int, int>>> adj(v_cnt + 1);
    for (int i = 0; i < e_cnt; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<int> dist(v_cnt + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start_u] = 0;
    pq.push({0, start_u});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 1; i <= v_cnt; ++i) {
        cout << dist[i] << (i == v_cnt ? "" : " ");
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