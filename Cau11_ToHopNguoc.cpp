#include <bits/stdc++.h>

using namespace std;

int n, k;
int x[20];
vector<vector<int>> res;

void try_comb(int i, int start) {
    for (int j = start; j <= n; j++) {
        x[i] = j;
        if (i == k) {
            vector<int> temp(x + 1, x + k + 1);
            res.push_back(temp);
        } else {
            try_comb(i + 1, j + 1);
        }
    }
}

void solve() {
    cin >> n >> k;
    res.clear();
    try_comb(1, 1);
    for (int i = res.size() - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            cout << res[i][j] << (j == k - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}