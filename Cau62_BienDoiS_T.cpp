#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long s, t;
    if (!(cin >> s >> t)) return;
    if (s == t) {
        cout << 0 << "\n";
        return;
    }
    
    queue<pair<long long, int>> q;
    unordered_set<long long> visited;
    
    q.push({s, 0});
    visited.insert(s);
    
    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();
        
        long long next1 = curr - 1;
        if (next1 == t) {
            cout << steps + 1 << "\n";
            return;
        }
        if (next1 > 0 && visited.find(next1) == visited.end()) {
            visited.insert(next1);
            q.push({next1, steps + 1});
        }
        
        long long next2 = curr * 2;
        if (next2 == t) {
            cout << steps + 1 << "\n";
            return;
        }
        if (next2 <= 20000 && visited.find(next2) == visited.end()) {
            visited.insert(next2);
            q.push({next2, steps + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    if (cin >> test) {
        while (test--) {
            solve();
        }
    }
    return 0;
}