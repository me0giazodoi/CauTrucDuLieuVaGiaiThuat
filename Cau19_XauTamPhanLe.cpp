#include <bits/stdc++.h>

using namespace std;

int n;
char c[] = {'A', 'B', 'C'};
vector<string> res;

void try_string(int i, string s) {
    if (i == n) {
        res.push_back(s);
        return;
    }
    for (int j = 0; j < 3; j++) {
        try_string(i + 1, s + c[j]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    try_string(0, "");
    for (size_t i = 0; i < res.size(); i += 2) {
        cout << (i + 1) << ": " << res[i] << "\n";
    }
    return 0;
}