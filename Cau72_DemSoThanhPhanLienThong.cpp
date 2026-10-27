
#include <bits/stdc++.h>
using namespace std;

int parent[1005], sz[1005];

int findRoot(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findRoot(parent[u]);
}

void unite(int u, int v) {
    u = findRoot(u);
    v = findRoot(v);

    if (u == v) return;

    if (sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (findRoot(i) == i) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
