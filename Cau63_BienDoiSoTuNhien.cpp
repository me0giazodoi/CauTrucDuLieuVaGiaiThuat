#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> dist;
    
    pq.push({0, n});
    dist[n] = 0;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (u == 1) {
            cout << d << "\n";
            return;
        }
        
        if (d > dist[u]) continue;
        
        if (u - 1 > 0) {
            if (dist.find(u - 1) == dist.end() || d + 1 < dist[u - 1]) {
                dist[u - 1] = d + 1;
                pq.push({d + 1, u - 1});
            }
        }
        
        for (int i = 2; i * i <= u; i++) {
            int v = u / i;
            int cost = (u % i) + 1;
            if (dist.find(v) == dist.end() || d + cost < dist[v]) {
                dist[v] = d + cost;
                pq.push({dist[v], v});
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