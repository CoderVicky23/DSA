#include <bits/stdc++.h>
using namespace std;

string removeKDigits(string& num, int k) {
    int n = num.length();
    if (k == n) return "0";
    stack <char> st;
    for (int i=0; i<n; i++) {
        if (k == 0) {
            st.push(num[i]);
            continue;
        }
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    int i = res.size() - 1;
    while (i >= 0 && res[i] == '0') i--;
    res.resize(i + 1);
    reverse(res.begin(), res.begin() + i + 1);
    return res;
}

int main() {
    string s = "1432219";
    int k = 3;
    cout << removeKDigits(s, k) << endl;
    return 0;
}