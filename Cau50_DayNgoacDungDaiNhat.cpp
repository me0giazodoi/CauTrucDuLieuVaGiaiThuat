#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;
    stack<int> st;
    st.push(-1);
    int max_len = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                max_len = max(max_len, i - st.top());
            }
        }
    }
    cout << max_len << "\n";
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