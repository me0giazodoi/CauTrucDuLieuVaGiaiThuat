#include <bits/stdc++.h>

using namespace std;

vector<int> dfs_parents(const vector<vector<int>> &adj, int n) {
    vector<int> parent(n + 1, -1);
    parent[1] = 0;

    vector<int> stack_u(n + 1);
    vector<int> stack_idx(n + 1);
    int top = -1;

    stack_u[++top] = 1;
    stack_idx[top] = 0;

    while (top >= 0) {
        int u = stack_u[top];
        int idx = stack_idx[top];

        if (idx >= (int)adj[u].size()) {
            top--;
        } else {
            stack_idx[top]++;
            int v = adj[u][idx];
            if (parent[v] == -1) {
                parent[v] = u;
                top++;
                stack_u[top] = v;
                stack_idx[top] = 0;
            }
        }
    }
    return parent;
}

void bfs_path(const vector<vector<int>> &adj, int start, int n, string &out_buf) {
    vector<int> parent(n + 1, -1);
    parent[start] = 0;
    
    vector<int> queue(n + 1);
    int head = 0, tail = 0;
    queue[tail++] = start;

    bool found = false;
    while (head < tail) {
        int u = queue[head++];
        if (u == 1) {
            found = true;
            break;
        }
        for (int v : adj[u]) {
            if (parent[v] == -1) {
                parent[v] = u;
                queue[tail++] = v;
                if (v == 1) {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }

    if (parent[1] == -1) {
        out_buf = "-1";
        return;
    }

    vector<int> path;
    int u = 1;
    while (u != 0) {
        path.push_back(u);
        u = parent[u];
    }

    out_buf = "";
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        out_buf += to_string(path[i]);
        if (i > 0) out_buf += " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent = dfs_parents(adj, n);
    string path_buf;

    for (int target = 2; target <= n; target++) {
        if (parent[target] == -1) {
            cout << "-1\n-1\n";
            continue;
        }

        vector<int> path;
        int u = target;
        while (u != 0) {
            path.push_back(u);
            u = parent[u];
        }

        for (int i = (int)path.size() - 1; i >= 0; i--) {
            cout << path[i] << (i > 0 ? " " : "");
        }
        cout << "\n";

        bfs_path(adj, target, n, path_buf);
        cout << path_buf << "\n";
    }

    return 0;
}