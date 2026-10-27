#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (!(cin >> s)) return 0;
    
    stack<char> left_st, right_st;
    
    for (char c : s) {
        if (c == '-') {
            if (!left_st.empty()) {
                left_st.pop();
            }
        } else if (c == '<') {
            if (!left_st.empty()) {
                right_st.push(left_st.top());
                left_st.pop();
            }
        } else if (c == '>') {
            if (!right_st.empty()) {
                left_st.push(right_st.top());
                right_st.pop();
            }
        } else {
            left_st.push(c);
        }
    }
    
    string left_str = "";
    while (!left_st.empty()) {
        left_str += left_st.top();
        left_st.pop();
    }
    reverse(left_str.begin(), left_str.end());
    
    string right_str = "";
    while (!right_st.empty()) {
        right_str += right_st.top();
        right_st.pop();
    }
    
    cout << left_str << right_str << "\n";
    
    return 0;
}