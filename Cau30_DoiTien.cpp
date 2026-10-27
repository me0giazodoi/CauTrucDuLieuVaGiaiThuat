#include <bits/stdc++.h>

using namespace std;

int coins[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

void solve() {
    int n;
    if (!(cin >> n)) return;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += n / coins[i];
        n %= coins[i];
    }
    cout << ans << "\n";
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