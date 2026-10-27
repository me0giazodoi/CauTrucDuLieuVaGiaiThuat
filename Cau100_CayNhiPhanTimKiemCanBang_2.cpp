#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    Node* root = new Node(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}

void preOrder(Node* root, vector<int>& res) {
    if (root == NULL) return;
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Node* root = sortedArrayToBST(a, 0, n - 1);
    vector<int> res;
    preOrder(root, res);
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