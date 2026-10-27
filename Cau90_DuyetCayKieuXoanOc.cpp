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

void spiralOrder(Node* root) {
    if (root == NULL) return;
    vector<int> res;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            res.push_back(curr->val);
            if (curr->right) s2.push(curr->right);
            if (curr->left) s2.push(curr->left);
        }
        while (!s2.empty()) {
            Node* curr = s2.top();
            s2.pop();
            res.push_back(curr->val);
            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
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
    spiralOrder(root);
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