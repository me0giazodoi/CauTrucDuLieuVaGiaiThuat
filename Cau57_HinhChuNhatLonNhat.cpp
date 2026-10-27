#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    stack<int> st;
    long long max_area = 0;
    int i = 0;
    while (i < n) {
        if (st.empty() || h[st.top()] <= h[i]) {
            st.push(i++);
        } else {
            int tp = st.top();
            st.pop();
            long long width = st.empty() ? i : (i - st.top() - 1);
            max_area = max(max_area, h[tp] * width);
        }
    }
    while (!st.empty()) {
        int tp = st.top();
        st.pop();
        long long width = st.empty() ? i : (i - st.top() - 1);
        max_area = max(max_area, h[tp] * width);
    }
    cout << max_area << "\n";
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