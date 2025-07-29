#include <bits/stdc++.h>
using namespace std;

int bottom_up(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    int ** arr = new int*[n+1];
    for (int i=0; i<=n; i++) {
        arr[i] = new int[m+1];
    }
    for (int i=0; i<=n; i++) {
        arr[i][0] = 0;
    }
    for (int j=0; j<=m; j++) {
        arr[0][j] = 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s1[i-1] == s2[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
            else arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
        }
    }
    int result = arr[n][m];
    for (int i=0; i<=n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return result;
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << bottom_up(s1, s2) << endl;
    return 0;
}