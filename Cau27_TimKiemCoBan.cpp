#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto it = lower_bound(a.begin(), a.end(), k);
    if (it != a.end() && *it == k) {
        cout << (it - a.begin() + 1) << "\n";
    } else {
        cout << "NO\n";
    }
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