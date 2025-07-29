#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    vector<vector<int>> result;
    result.push_back({1});
    for (int i=1; i<n; i++) {
        vector <int> a;
        a.push_back(1);
        for (int j=0; j<i-1; j++) {
            a.push_back(result[i-1][j] + result[i-1][j+1]);
        }
        a.push_back(1);
        result.push_back(a);
    }
    for (vector<int>& a: result) {
        for (int& b: a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}