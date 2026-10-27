#include <bits/stdc++.h>

using namespace std;

struct Segment {
    int start, finish;
};

bool compareSegments(Segment a, Segment b) {
    return a.finish < b.finish;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<Segment> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].start >> segs[i].finish;
    }
    sort(segs.begin(), segs.end(), compareSegments);
    int count = 0;
    int last_finish = -1;
    for (int i = 0; i < n; i++) {
        if (segs[i].start >= last_finish) {
            count++;
            last_finish = segs[i].finish;
        }
    }
    cout << count << "\n";
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