#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long sum = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = sum;
        sum = (sum + dp[i]) % MOD;
        if (i >= k) {
            sum = (sum - dp[i - k] + MOD) % MOD;
        }
    }
    cout << dp[n] << "\n";
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