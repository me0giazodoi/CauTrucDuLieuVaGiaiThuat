#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    queue<string> q;
    q.push("1");
    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();
        cout << s << (i == n ? "" : " ");
        q.push(s + "0");
        q.push(s + "1");
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