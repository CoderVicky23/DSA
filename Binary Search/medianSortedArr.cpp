#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& n1, vector<int>& n2) {
    int m = n1.size();
    int n = n2.size();
    if (m > n) return median(n2, n1);
    int total = m + n;
    int half = (total + 1)/2;
    int low = 0, high = m;
    while (low <= high) {
        int mid1 = low + (high - low)/2;
        int mid2 = half - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m) r1 = n1[mid1];
        if (mid2 < m) r2 = n2[mid2];
        if (mid1 >= 0) l1 = n1[mid1-1];
        if (mid2 >= 0) l2 = n2[mid2-1];
        if (l1 > r2) high = mid1 - 1;
        else if (l2 > r1) low = mid1 + 1;
        else {
            if (n%2) return max(l1, l2);
            return ((double) (max(l1, l2) + min(r1, r2))) / 2.0;
        }
    }
    return 0;
}



// double median(vector<int>& n1, vector<int>& n2) {
//     int m = n1.size();
//     int n = n2.size();
//     if (m > n) return median(n2, n1);
//     int total = m + n;
//     int half = total/2;
//     int low = 0, high = m;
//     double res = -1;
//     while (low <= high) {
//         int mid = low + (high - low)/2;
//         int l1 = n1[mid-1];
//         int l2 = n2[n-mid-1];
//         int r1 = n1[mid];
//         int r2 = n2[n-mid];
//         if (l1 > r2) {
//             high = mid - 1;
//         } else if (l2 > r2) {
//             low = mid + 1;
//         } else {
//             if (total%2) {
//                 res = (double) (max(l1, l2) + min(r1, r2))/(double) 2;
//             } else {
//                 res = min(r1, r2);
//             }
//             break;
//         }
//     }
//     return res;
// }



int main() {
    vector<int> n1 = {2,4,5,7};
    vector<int> n2 = {1,3,9};
    cout << median(n1, n2) << endl;
    return 0;
}