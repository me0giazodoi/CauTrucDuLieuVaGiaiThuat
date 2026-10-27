#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(Node* root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->val == u) {
        if (c == 'L') root->left = new Node(v);
        else root->right = new Node(v);
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr->val == u) {
            if (c == 'L') curr->left = new Node(v);
            else curr->right = new Node(v);
            return;
        }
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

bool check(Node* root) {
    if (root == NULL) return true;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int leaf_depth = -1;
    while (!q.empty()) {
        auto [curr, depth] = q.front();
        q.pop();
        if (!curr->left && !curr->right) {
            if (leaf_depth == -1) {
                leaf_depth = depth;
            } else if (leaf_depth != depth) {
                return false;
            }
        }
        if (curr->left) q.push({curr->left, depth + 1});
        if (curr->right) q.push({curr->right, depth + 1});
    }
    return true;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == NULL) {
            root = new Node(u);
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            insert(root, u, v, c);
        }
    }
    if (check(root)) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
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