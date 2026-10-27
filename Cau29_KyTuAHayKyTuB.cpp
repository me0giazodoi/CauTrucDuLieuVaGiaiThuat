#include <bits/stdc++.h>

using namespace std;

long long f[93];

void precompute() {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 92; i++) {
        f[i] = f[i - 2] + f[i - 1];
    }
}

char find_char(int n, long long i) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (i <= f[n - 2]) {
        return find_char(n - 2, i);
    } else {
        return find_char(n - 1, i - f[n - 2]);
    }
}

void solve() {
    int n;
    long long i;
    if (!(cin >> n >> i)) return;
    cout << find_char(n, i) << "\n";
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