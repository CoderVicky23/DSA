#include <bits/stdc++.h>
using namespace std;

vector<int> nse(vector<int>& arr) {
    int n = arr.size();
    vector<int> res (n);
    stack <int> st;
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (st.empty()) {
            res[i] = st.top();
            st.push(i);
        } else {
            res[i] = n;
            st.push(i);
        }
    }
    return res;
}

vector<int> pse(vector<int>& arr) {
    int n = arr.size();
    vector<int> res (n);
    stack <int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && st.top() >= arr[i]) st.pop();
        if (st.empty()) {
            res[i] = st.top();
            st.push(arr[i]);
        } else {
            res[i] = -1;
            st.push(i);
        }
    }
    return res;
}

int largestRect(vector<int>& arr) {
    int n = arr.size();
    vector<int> ns = nse(arr);
    vector<int> ps = pse(arr);
    int maxi = 0;
    for (int i=0; i<n; i++) {
        int area = arr[i] * (ns[i] - ps[i] - 1);
        maxi = max(maxi, area);
    }
    return maxi;
}

int main() {
    vector <int> arr = {2,1,5,6,2,3};
    cout << largestRect(arr) << endl;
    return 0;
}