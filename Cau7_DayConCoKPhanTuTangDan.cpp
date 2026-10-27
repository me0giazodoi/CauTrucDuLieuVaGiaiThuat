#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[20];
vector<int> cur;

void Try(int start) {
    if ((int)cur.size() == K) {
        for (int i = 0; i < K; i++) {
            if (i > 0) cout << " ";
            cout << cur[i];
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++) {
        cur.push_back(A[i]);
        Try(i + 1);
        cur.pop_back();
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        for (int i = 0; i < N; i++)
            cin >> A[i];

        sort(A, A + N);

        cur.clear();
        Try(0);
    }

    return 0;
}