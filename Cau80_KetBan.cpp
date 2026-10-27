#include <bits/stdc++.h>

using namespace std;

int parent_dsu[100005];
int sz[100005];

int find_set(int v) {
    if (v == parent_dsu[v])
        return v;
    return parent_dsu[v] = find_set(parent_dsu[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent_dsu[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    for (int i = 1; i <= n; ++i) {
        parent_dsu[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }
    int max_sz = 0;
    for (int i = 1; i <= n; ++i) {
        if (find_set(i) == i) {
            max_sz = max(max_sz, sz[i]);
        }
    }
    cout << max_sz << "\n";
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