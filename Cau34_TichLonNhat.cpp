#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long p1 = a[n - 1] * a[n - 2];
    long long p2 = a[0] * a[1];
    long long p3 = a[n - 1] * a[n - 2] * a[n - 3];
    long long p4 = a[0] * a[1] * a[n - 1];
    long long ans = max({p1, p2, p3, p4});
    cout << ans << "\n";
    return 0;
}