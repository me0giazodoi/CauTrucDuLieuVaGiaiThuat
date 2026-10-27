#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    stack<int> st;
    bool found = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int j = st.top();
            st.pop();
            if (i - j == 2) {
                found = true;
                break;
            }
            bool has_op = false;
            for (int k = j + 1; k < i; k++) {
                if (s[k] == '+' || s[k] == '-' || s[k] == '*' || s[k] == '/') {
                    has_op = true;
                    break;
                }
            }
            if (!has_op) {
                found = true;
                break;
            }
        }
    }
    if (found) cout << "Yes\n";
    else cout << "No\n";
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