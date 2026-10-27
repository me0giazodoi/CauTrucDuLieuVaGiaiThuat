#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[20];

void Try(int pos, int start, int sum) {
    if (pos == k) {
        if (sum % 2 == 0) {
            for (int i = 0; i < k; i++) {
                if (i > 0) cout << " ";
                cout << a[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = start; i <= n - (k - pos) + 1; i++) {
        a[pos] = i;
        Try(pos + 1, i + 1, sum + i);
    }
}

int main() {
    cin >> n >> k;
    Try(0, 1, 0);
    return 0;
}