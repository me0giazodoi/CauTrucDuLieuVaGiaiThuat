#include <bits/stdc++.h>

using namespace std;

struct Job {
    int start, finish;
};

bool compareJobs(Job a, Job b) {
    return a.finish < b.finish;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].start >> jobs[i].finish;
    }
    sort(jobs.begin(), jobs.end(), compareJobs);
    int count = 0;
    int last_finish = -1;
    for (int i = 0; i < n; i++) {
        if (jobs[i].start >= last_finish) {
            count++;
            last_finish = jobs[i].finish;
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