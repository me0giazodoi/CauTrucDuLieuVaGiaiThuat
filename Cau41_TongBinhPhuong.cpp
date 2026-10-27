#include <bits/stdc++.h>

using namespace std;

int dp[10005];

void precompute() {
    for (int i = 1; i <= 10000; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}