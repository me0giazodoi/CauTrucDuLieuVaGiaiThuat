#include <bits/stdc++.h>
using namespace std;

void sinh(string s, int n) {
    if (s.size() == n) {
        cout << s << " ";
        return;
    }

    sinh(s + "6", n);
    sinh(s + "8", n);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << (1 << N) << '\n';
        sinh("", N);
        cout << '\n';
    }

    return 0;
}