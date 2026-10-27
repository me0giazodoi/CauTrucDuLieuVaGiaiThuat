#include <bits/stdc++.h>

using namespace std;

int n;
string a[20];
int x[20];
set<string> res;

void try_comb(int i, int k, int start) {
    for (int j = start; j < n; j++) {
        x[i] = j;
        if (i == k) {
            string s = "";
            for (int l = 1; l <= k; l++) {
                s += a[x[l]];
            }
            res.insert(s);
        } else {
            try_comb(i + 1, k, j + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int k = 1; k <= n; k++) {
        try_comb(1, k, 0);
    }
    
    for (const string &s : res) {
        cout << s << "\n";
    }
    
    return 0;
}