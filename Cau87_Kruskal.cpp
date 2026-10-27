#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent_dsu[1005];
int sz[1005];

int find_set(int v) {
    if (v == parent_dsu[v])
        return v;
    return parent_dsu[v] = find_set(parent_dsu[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent_dsu[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

void solve() {
    int v_cnt, e_cnt;
    if (!(cin >> v_cnt >> e_cnt)) return;
    vector<Edge> edges(e_cnt);
    for (int i = 0; i < e_cnt; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= v_cnt; ++i) {
        parent_dsu[i] = i;
        sz[i] = 1;
    }
    
    int total_weight = 0;
    int count_edges = 0;
    
    for (const auto& edge : edges) {
        if (union_sets(edge.u, edge.v)) {
            total_weight += edge.w;
            count_edges++;
            if (count_edges == v_cnt - 1) break;
        }
    }
    
    cout << total_weight << "\n";
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