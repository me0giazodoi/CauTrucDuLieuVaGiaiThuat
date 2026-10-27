#include <bits/stdc++.h>

using namespace std;

string s;
int k, n;
int x[20];
vector<string> res;

void try_comb(int i, int start) {
    for (int j = start; j < n; j++) {
        x[i] = j;
        if (i == k) {
            string temp = "";
            for (int l = 1; l <= k; l++) {
                temp += s[x[l]];
            }
            res.push_back(temp);
        } else {
            try_comb(i + 1, j + 1);
        }
    }
}

void solve() {
    cin >> s >> k;
    n = (int)s.length();
    res.clear();
    try_comb(1, 0);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
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