#include <bits/stdc++.h>
using namespace std;

int N;
string s;

void Try(int a, int b, int c) {
    if (a + b + c > N) return;

    if (a > 0 && b > 0 && c > 0 && a <= b && b <= c) {
        cout << s << '\n';
    }

    if ((int)s.size() == N) return;

    for (char ch = 'A'; ch <= 'C'; ch++) {
        s += ch;
        Try(a + (ch == 'A'), b + (ch == 'B'), c + (ch == 'C'));
        s.pop_back();
    }
}

int main() {
    cin >> N;

    for (int len = 3; len <= N; len++) {
        s.clear();
        function<void(int,int,int)> dfs = [&](int a, int b, int c) {
            if ((int)s.size() == len) {
                if (a > 0 && b > 0 && c > 0 && a <= b && b <= c)
                    cout << s << '\n';
                return;
            }

            for (char ch = 'A'; ch <= 'C'; ch++) {
                s += ch;
                dfs(a + (ch == 'A'), b + (ch == 'B'), c + (ch == 'C'));
                s.pop_back();
            }
        };
        dfs(0, 0, 0);
    }

    return 0;
}