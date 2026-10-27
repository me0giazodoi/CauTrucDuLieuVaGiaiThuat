#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    if (!(cin >> n >> s)) return 0;
    if (s == 0 || s > 9 * n) {
        cout << "-1 -1\n";
        return 0;
    }
    
    vector<int> sm(n, 0);
    int temp_s = s - 1;
    for (int i = n - 1; i > 0; i--) {
        if (temp_s >= 9) {
            sm[i] = 9;
            temp_s -= 9;
        } else {
            sm[i] = temp_s;
            temp_s = 0;
        }
    }
    sm[0] = 1 + temp_s;
    
    vector<int> lg(n, 0);
    temp_s = s;
    for (int i = 0; i < n; i++) {
        if (temp_s >= 9) {
            lg[i] = 9;
            temp_s -= 9;
        } else {
            lg[i] = temp_s;
            temp_s = 0;
        }
    }
    
    for (int i = 0; i < n; i++) cout << sm[i];
    cout << " ";
    for (int i = 0; i < n; i++) cout << lg[i];
    cout << "\n";
    
    return 0;
}