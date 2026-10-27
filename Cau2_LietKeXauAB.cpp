#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void Try(int i) {
    if (i == n) {
        bool hasA = false, hasB = false;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'A') hasA = true;
            if (s[j] == 'B') hasB = true;
        }

        if (hasA && hasB) {
            cout << s << endl;
        }
        return;
    }

    s[i] = 'A';
    Try(i + 1);

    s[i] = 'B';
    Try(i + 1);
}

int main() {
    cin >> n;
    s.resize(n);
    Try(0);
    return 0;
}
