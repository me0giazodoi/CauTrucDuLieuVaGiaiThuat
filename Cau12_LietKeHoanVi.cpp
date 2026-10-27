#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        if (i != m) {
            a.push_back(i);
        }
    }
    do {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << m << "\n";
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}