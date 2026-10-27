#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<string> res;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s.length() <= n) {
            res.push_back(s);
            q.push(s + "6");
            q.push(s + "8");
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
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