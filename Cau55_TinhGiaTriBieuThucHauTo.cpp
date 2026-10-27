#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;
    stack<long long> st;
    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            long long op2 = st.top(); st.pop();
            long long op1 = st.top(); st.pop();
            long long res = 0;
            if (c == '+') res = op1 + op2;
            else if (c == '-') res = op1 - op2;
            else if (c == '*') res = op1 * op2;
            else if (c == '/') res = op1 / op2;
            st.push(res);
        }
    }
    cout << st.top() << "\n";
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