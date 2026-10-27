#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    set<string> st;
    int total = 1 << n;

    for (int mask = 1; mask < total; mask++) {
        string s = "";
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                s += words[i];
            }
        }
        st.insert(s);
    }

    for (const string &s : st) {
        cout << s << "\n";
    }

    return 0;
}