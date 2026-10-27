#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long stt = 0;
    string s(N, '0');

    function<void(int)> Try = [&](int pos) {
        if (pos == N) {
            int sum = 0;
            for (char c : s) sum += c - '0';

            if (sum % 2 == 1) {
                cout << stt + 2 << ": " << s << '\n';
                stt += 2;
            }
            return;
        }

        for (char c = '0'; c <= '2'; c++) {
            s[pos] = c;
            Try(pos + 1);
        }
    };

    Try(0);
    return 0;
}