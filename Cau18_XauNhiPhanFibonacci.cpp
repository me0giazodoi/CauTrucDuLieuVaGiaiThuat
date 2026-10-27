#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int total = 1 << n;
    vector<string> a;
    for (int i = 0; i < total; i++) {
        string s = "";
        for (int j = n - 1; j >= 0; j--) {
            if ((i >> j) & 1) s += '1';
            else s += '0';
        }
        a.push_back(s);
    }

    vector<int> f(100);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 90; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    set<int> fib_set;
    for (int i = 1; i <= 25; i++) {
        fib_set.insert(f[i]);
    }

    for (int i = 1; i <= total; i++) {
        if (fib_set.count(i)) {
            cout << i << ":";
            for (char c : a[i - 1]) {
                cout << " " << c;
            }
            cout << "\n";
        }
    }

    return 0;
}