#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int m = a.size();
    int n = b.size();
    if (m > n) return kthElement(b, a, k);
    // int low = 0, high = m;
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;
        // int mid2 = abs(mid1 - k);
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 > 0) l1 = a[mid1-1];
        if (mid2 > 0) l2 = b[mid2-1];
        if (mid1 < m) r1 = a[mid1];
        if (mid2 < n) r2 = b[mid2];
        if (l1 > r2) high = mid1 - 1;
        else if (l2 > r1) low = mid1 + 1;
        else {
            return max(l1, l2);
        }
    }
    return -1;
}

int main() {
    vector <int> a = {}, b = {10, 11, 12, 13 };
    int k = 3;
    cout << kthElement(a, b, k) << endl;
    return 0;
}