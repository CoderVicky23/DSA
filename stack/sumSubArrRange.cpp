#include <bits/stdc++.h>
using namespace std;

vector<int> pse(vector<int>& arr) {
    int n = arr.size();
    vector<int> res (n);
    stack <int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if (st.empty()) {
            res[i] = -1;
            st.push(i);
        } else {
            res[i] = st.top();
            st.push(i);
        }
    }
    return res;
}

vector<int> nse(vector<int>& arr) {
    int n = arr.size();
    vector<int> res (n);
    stack <int> st;
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (st.empty()) {
            res[i] = n;
            st.push(i);
        } else {
            res[i] = st.top();
            st.push(i);
        }
    }
    return res;
}

vector<int> pge(vector<int>& arr) {
    int n = arr.size();
    vector<int> res (n);
    stack<int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        if (st.empty()) {
            res[i] = -1;
            st.push(i);
        } else {
            res[i] = st.top();
            st.push(i);
        }
    }
    return res;
}

vector<int> nge(vector<int>& arr) {
    int n = arr.size();
    vector<int> res (n);
    stack<int> st;
    for (int i=n-1; i>=0; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (st.empty()) {
            res[i] = n;
            st.push(i);
        } else {
            res[i] = st.top();
            st.push(i);
        }
    }
    return res;
}

long long sumSubArr(vector<int>& arr) {
    int n = arr.size();
    vector<int> ns = nse(arr);
    vector<int> ps = pse(arr);
    vector<int> ng = nge(arr);
    vector<int> pg = pge(arr);
    long long smaller = 0;
    long long greater = 0;
    for (int i=0; i<n; i++) {
        smaller += (long long) arr[i] * (ns[i] - i) * (i - ps[i]);
        greater += (long long) arr[i] * (ng[i] - i) * (i - pg[i]);
    }
    return greater - smaller;
}

int main() {
    vector<int> arr = {1, 4, 3, 2};
    cout << sumSubArr(arr) << endl;
    return 0;
}