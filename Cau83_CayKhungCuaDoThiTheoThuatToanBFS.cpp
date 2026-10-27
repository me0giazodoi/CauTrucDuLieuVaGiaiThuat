
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, u;
        cin >> N >> M >> u;

        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(N + 1, false);
        vector<pair<int, int>> edges;
        queue<int> q;

        visited[u] = true;
        q.push(u);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int x : adj[v]) {
                if (!visited[x]) {
                    visited[x] = true;
                    edges.push_back({v, x});
                    q.push(x);
                }
            }
        }

        if ((int)edges.size() != N - 1) {
            cout << -1 << '\n';
        } else {
            for (auto e : edges) {
                cout << e.first << ' ' << e.second << '\n';
            }
        }
    }

    return 0;
}
