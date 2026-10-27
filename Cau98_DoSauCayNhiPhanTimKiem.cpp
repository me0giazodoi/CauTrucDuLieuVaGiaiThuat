#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int depth;
    Node* left;
    Node* right;
    Node(int x, int d) : val(x), depth(d), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val, int depth, int& max_depth) {
    if (root == NULL) {
        max_depth = max(max_depth, depth);
        return new Node(val, depth);
    }
    if (val < root->val) {
        root->left = insert(root->left, val, depth + 1, max_depth);
    } else if (val > root->val) {
        root->right = insert(root->right, val, depth + 1, max_depth);
    }
    return root;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    Node* root = NULL;
    int max_depth = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val, 0, max_depth);
    }
    cout << max_depth << "\n";
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