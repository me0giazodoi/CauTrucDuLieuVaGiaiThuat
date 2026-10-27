#include <bits/stdc++.h>

using namespace std;

long long solve_k(int n, long long k) {
    long long mid = 1LL << (n - 1);
    if (k == mid) return n;
    if (k < mid) return solve_k(n - 1, k);
    return solve_k(n - 1, k - mid);
}

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    cout << solve_k(n, k) << "\n";
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