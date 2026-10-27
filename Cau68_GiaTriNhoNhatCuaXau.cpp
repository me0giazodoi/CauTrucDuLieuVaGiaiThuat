#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long k;
    if (!(cin >> k)) return;
    string s;
    cin >> s;
    
    vector<long long> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    
    priority_queue<long long> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push(freq[i]);
        }
    }
    
    while (k > 0 && !pq.empty()) {
        long long top = pq.top();
        pq.pop();
        top--;
        k--;
        if (top > 0) {
            pq.push(top);
        }
    }
    
    long long ans = 0;
    while (!pq.empty()) {
        long long val = pq.top();
        pq.pop();
        ans += val * val;
    }
    
    cout << ans << "\n";
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