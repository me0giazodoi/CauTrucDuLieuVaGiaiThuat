
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
int parentDFS[1005], parentBFS[1005];
bool visited[1005];

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parentDFS[v] = u;
            DFS(v);
        }
    }
}

void BFS() {
    queue<int> q;
    fill(visited, visited + n + 1, false);
    fill(parentBFS, parentBFS + n + 1, -1);

    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parentBFS[v] = u;
                q.push(v);
            }
        }
    }
}

void printDFS(int u) {
    if (u != 1 && parentDFS[u] == 0) {
        cout << -1 << '\n';
        return;
    }

    vector<int> path;
    while (u != 0) {
        path.push_back(u);
        if (u == 1) break;
        u = parentDFS[u];
    }

    if (path.back() != 1) {
        cout << -1 << '\n';
        return;
    }

    reverse(path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++) {
        if (i) cout << ' ';
        cout << path[i];
    }
    cout << '\n';
}

void printBFS(int u) {
    if (!visited[u]) {
        cout << -1 << '\n';
        return;
    }

    cout << u;
    while (u != 1) {
        u = parentBFS[u];
        cout << ' ' << u;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    fill(parentDFS, parentDFS + n + 1, 0);
    fill(visited, visited + n + 1, false);
    DFS(1);

    bool reachableDFS[1005];
    copy(visited, visited + n + 1, reachableDFS);

    BFS();

    for (int i = 2; i <= n; i++) {
        if (!reachableDFS[i]) {
            cout << -1 << '\n';
        } else {
            printDFS(i);
        }
        printBFS(i);
    }

    return 0;
}
