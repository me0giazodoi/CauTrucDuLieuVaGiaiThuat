#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

void postOrder(Node* root, vector<int>& res) {
    if (root == NULL) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->val);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    vector<int> res;
    postOrder(root, res);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
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