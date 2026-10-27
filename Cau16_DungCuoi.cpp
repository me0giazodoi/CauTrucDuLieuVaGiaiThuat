#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string m;
    cin >> m;
    vector<string> b;
    for (int i = 0; i < n; i++) {
        if (a[i] != m) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    do {
        for (int i = 0; i < (int)b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << m << "\n";
    } while (next_permutation(b.begin(), b.end()));
    return 0;
}