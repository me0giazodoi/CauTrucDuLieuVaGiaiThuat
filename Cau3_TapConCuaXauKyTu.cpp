#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        vector<string> res;

        for (int mask = 1; mask < (1 << n); mask++) {
            string sub = "";

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sub += s[i];
                }
            }

            res.push_back(sub);
        }

        sort(res.begin(), res.end());

        for (int i = 0; i < (int)res.size(); i++) {
            if (i > 0) cout << " ";
            cout << res[i];
        }

        cout << '\n';
    }

    return 0;
}
