#include <bits/stdc++.h>
using namespace std;

long long power(long long m, long long n) {
    if (m == 0) return 1;
    if (m%2) {
        return n * power(m-1, n);
    } else {
        long long temp = power(m/2, n);
        return temp * temp;
    }
}

int main() {
    int n = 30;
    int m = INT_MAX;
    int h = m;
    int l = 1;
    int res = -1;
    while (l <= h) {
        int k = (l + h)/2;
        long long r = power((long) n, (long) k);
        if (r == m) {
            res = k;
            break;
        }
        else if (r > m) {
            h = k - 1;
        } else {
            l = k + 1;
        }
    }
    cout << res << endl;
    return 0;
}