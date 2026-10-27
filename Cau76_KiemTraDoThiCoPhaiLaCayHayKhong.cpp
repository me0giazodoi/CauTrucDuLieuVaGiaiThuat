#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> parent;
    DSU(int _n) : n(_n), parent(_n + 1) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    DSU dsu(n);
    bool is_tree = true;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (!dsu.unite(u, v)) {
            is_tree = false;
        }
    }
    
    if (is_tree) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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