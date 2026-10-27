#include <bits/stdc++.h>

using namespace std;

string rotate_left(string s) {
    string t = s;
    t[0] = s[3];
    t[1] = s[0];
    t[3] = s[4];
    t[4] = s[1];
    return t;
}

string rotate_right(string s) {
    string t = s;
    t[1] = s[4];
    t[2] = s[1];
    t[4] = s[5];
    t[5] = s[2];
    return t;
}

void solve() {
    string start = "", target = "";
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        start += c;
    }
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        target += c;
    }
    
    if (start == target) {
        cout << 0 << "\n";
        return;
    }
    
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    
    q.push({start, 0});
    visited.insert(start);
    
    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();
        
        string next1 = rotate_left(curr);
        if (next1 == target) {
            cout << steps + 1 << "\n";
            return;
        }
        if (visited.find(next1) == visited.end()) {
            visited.insert(next1);
            q.push({next1, steps + 1});
        }
        
        string next2 = rotate_right(curr);
        if (next2 == target) {
            cout << steps + 1 << "\n";
            return;
        }
        if (visited.find(next2) == visited.end()) {
            visited.insert(next2);
            q.push({next2, steps + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}