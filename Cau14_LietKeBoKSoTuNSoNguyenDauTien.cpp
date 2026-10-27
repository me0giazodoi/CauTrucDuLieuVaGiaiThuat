#include <bits/stdc++.h>

using namespace std;

int n, k;
int x[20];

void print() {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << (i == k ? "" : " ");
    }
    cout << "\n";
}

void try_comb(int i, int start) {
    for (int j = start; j <= n; j++) {
        x[i] = j;
        if (i == k) {
            print();
        } else {
            try_comb(i + 1, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    try_comb(1, 1);
    return 0;
}