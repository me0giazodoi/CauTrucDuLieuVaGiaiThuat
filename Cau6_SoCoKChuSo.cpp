#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        int K;
        cin >> S >> K;

        set<string> ans;
        int n = S.size();

        function<void(string, int)> backtrack =
            [&](string cur, int start) {
                if ((int)cur.size() == K) {
                    if (cur[0] != '0')
                        ans.insert(cur);
                    return;
                }

                for (int i = start; i < n; i++) {
                    backtrack(cur + S[i], i + 1);
                }
            };

        backtrack("", 0);

        for (const string &x : ans) {
            cout << x << '\n';
        }
    }

    return 0;
}