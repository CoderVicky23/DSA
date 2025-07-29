#include <bits/stdc++.h>
using namespace std;

int n, m;
int** arr = nullptr;

int solve(string& s1, string& s2, int i, int j) {
    if (arr[i][j] != -1) return arr[i][j];
    if (i == n || j == m) return 0;
    if (s1[i] == s2[j]) return arr[i][j] = 1 + (s1, s2, i+1, j+1);
    else return arr[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
}

int longestCommonSubs(string& s1, string& s2) {
    n = s1.length();
    m = s2.length();
    return 1 + solve(s1, s2, 0, 0);
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    n = s1.length();
    m = s2.length();
    arr = new int*[n];
    for (int i=0; i<n; i++){
        arr[i] = new int[m];
        for (int j=0; j<m; j++) {
            arr[i][j] = -1;
        }
    }
    cout << longestCommonSubs(s1, s2) << endl;
    // Free allocated memory
    for (int i=0; i<n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}