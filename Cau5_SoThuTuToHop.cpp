#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> a(K);
        for (int i = 0; i < K; i++) {
            cin >> a[i];
        }

        long long ans = 1;

        for (int i = 0; i < K; i++) {
            int start = (i == 0 ? 1 : a[i - 1] + 1);

            for (int x = start; x < a[i]; x++) {
                long long ways = 1;

                for (int j = 1; j <= K - i - 1; j++) {
                    ways = ways * (N - x - j + 1) / j;
                }

                ans += ways;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}