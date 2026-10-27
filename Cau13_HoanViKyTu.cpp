#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c1, c2;
    cin >> c1 >> c2;
    if (c1 > c2) swap(c1, c2);
    string s = "";
    for (char c = c1; c <= c2; c++) {
        s += c;
    }
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}