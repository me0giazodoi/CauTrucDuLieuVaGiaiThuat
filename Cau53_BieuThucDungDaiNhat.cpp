#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;
    stack<char> st;
    int pairs = 0;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (!st.empty()) {
                st.pop();
                pairs++;
            }
        }
    }
    cout << pairs * 2 << "\n";
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