#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void Try(int i, int cnt) {
    if (i == n) {
        if (cnt % 2 == 0) {
            for (int j = 0; j < n; j++) {
                cout << s[j];
                if (j < n - 1) cout << ' ';
            }
            cout << '\n';
        }
        return;
    }

    s[i] = '0';
    Try(i + 1, cnt);

    s[i] = '1';
    Try(i + 1, cnt + 1);
}

int main() {
    cin >> n;
    s.resize(n);
    Try(0, 0);
    return 0;
}
