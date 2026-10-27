
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, s;
        cin >> N >> M >> s;

        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(N + 1, -1);
        vector<bool> visited(N + 1, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (i == s) continue;

            if (!visited[i]) {
                cout << "No path\n";
                continue;
            }

            vector<int> path;
            int cur = i;

            while (cur != -1) {
                path.push_back(cur);
                cur = parent[cur];
            }

            reverse(path.begin(), path.end());

            for (int j = 0; j < (int)path.size(); j++) {
                if (j > 0) cout << ' ';
                cout << path[j];
            }
            cout << '\n';
        }
    }

    return 0;
}
