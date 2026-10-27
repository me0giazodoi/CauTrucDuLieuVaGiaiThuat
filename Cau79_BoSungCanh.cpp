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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    for (int i = 1; i <= n; ++i) {
        parent_dsu[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }
    int root1 = find_set(1);
    int max_other = 0;
    for (int i = 1; i <= n; ++i) {
        if (find_set(i) == i && i != root1) {
            max_other = max(max_other, sz[i]);
        }
    }
    cout << sz[root1] + max_other << "\n";
    return 0;
}