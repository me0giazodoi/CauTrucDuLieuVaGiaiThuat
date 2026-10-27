#include <bits/stdc++.h>

using namespace std;

string dp[105][10005];
bool visited[105][10005];

void precompute() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 10000; j++) {
            dp[i][j] = "-1";
        }
    }
    dp[0][0] = "";
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while (!q.empty()) {
        auto [sum_a, sum_b] = q.front();
        q.pop();
        
        for (int d = (sum_a == 0 ? 1 : 0); d <= 9; d++) {
            int na = sum_a + d;
            int nb = sum_b + d * d;
            if (na <= 100 && nb <= 10000) {
                string next_val = dp[sum_a][sum_b] + to_string(d);
                if (dp[na][nb] == "-1" || next_val.length() < dp[na][nb].length() || (next_val.length() == dp[na][nb].length() && next_val < dp[na][nb])) {
                    dp[na][nb] = next_val;
                    if (!visited[na][nb]) {
                        visited[na][nb] = true;
                        q.push({na, nb});
                    }
                }
            }
        }
    }
}

void solve() {
    int a, b;
    if (!(cin >> a >> b)) return;
    if (a > 100 || b > 10000 || dp[a][b] == "-1" || dp[a][b].length() > 100) {
        cout << "-1\n";
    } else {
        cout << dp[a][b] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}