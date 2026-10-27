#include <bits/stdc++.h>

using namespace std;

string solve_test() {
    int n;
    if (!(cin >> n)) return "";
    queue<string> q;
    q.push("9");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        
        long long rem = 0;
        for (char c : s) {
            rem = (rem * 10 + (c - '0')) % n;
        }
        if (rem == 0) {
            return s;
        }
        
        q.push(s + "0");
        q.push(s + "9");
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            cout << solve_test() << "\n";
        }
    }
    return 0;
}