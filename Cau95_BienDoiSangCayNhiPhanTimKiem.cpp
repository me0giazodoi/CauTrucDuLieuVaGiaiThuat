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

void collectNodes(Node* root, vector<int>& nodes) {
    if (!root) return;
    nodes.push_back(root->val);
    collectNodes(root->left, nodes);
    collectNodes(root->right, nodes);
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
    vector<int> nodes;
    collectNodes(root, nodes);
    sort(nodes.begin(), nodes.end());
    for (int i = 0; i < nodes.size(); ++i) {
        cout << nodes[i] << (i == nodes.size() - 1 ? "" : " ");
    }
    cout << "\n";
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