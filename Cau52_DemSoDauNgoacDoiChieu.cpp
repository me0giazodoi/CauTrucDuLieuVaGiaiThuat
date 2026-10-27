#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;
    int open = 0, res = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                res++;
                open++;
            }
        }
    }
    res += open / 2;
    cout << res << "\n";
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