#include <bits/stdc++.h>

using namespace std;

void getPostOrder(int left, int right, const vector<int>& a, vector<int>& result) {
    if (left > right) return;
    
    int mid = left + (right - left) / 2;
    
    getPostOrder(left, mid - 1, a, result);
    getPostOrder(mid + 1, right, a, result);
    result.push_back(a[mid]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<int> result;
    result.reserve(n);
    
    getPostOrder(0, n - 1, a, result);
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}