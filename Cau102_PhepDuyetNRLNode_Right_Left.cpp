#include <bits/stdc++.h>

using namespace std;

struct Node {
    string val;
    Node* left;
    Node* right;
    Node(string v) : val(v), left(nullptr), right(nullptr) {}
};

void nrl(Node* root, vector<string>& res) {
    if (!root) return;
    res.push_back(root->val);
    nrl(root->right, res);
    nrl(root->left, res);
}

void solve() {
    string s;
    getline(cin, s);
    if (s.empty()) return;
    stringstream ss(s);
    string token;
    if (!(ss >> token)) return;

    Node* root = new Node(token);
    queue<Node*> q;
    q.push(root);

    while (!q.empty() && ss >> token) {
        Node* curr = q.front();
        q.pop();

        if (token != "N") {
            curr->left = new Node(token);
            q.push(curr->left);
        }

        if (ss >> token) {
            if (token != "N") {
                curr->right = new Node(token);
                q.push(curr->right);
            }
        }
    }

    vector<string> res;
    nrl(root, res);
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        string dummy;
        getline(cin, dummy);
        while (t--) {
            solve();
        }
    }
    return 0;
}