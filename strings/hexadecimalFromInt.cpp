#include <bits/stdc++.h>
using namespace std;

char value(int n) {
    if (n < 10) return '0' + n;
    n -= 10;
    return 'A' + n;
}
string solve(long long num, int base) {
    string res;
    while (num > 0) {
        res += value(num%base);
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}
string concatHex36(int n) {
    long long n_sq = n*n;
    long long n_cb = n_sq * n;
    
    string hd = ""; // store result;
    
    hd += solve(n_sq, 16);
    hd += solve(n_cb, 36);

    return hd;
}

int main() {
    int n = 13;
    cout << concatHex36(n) << endl;
    return 0;
}