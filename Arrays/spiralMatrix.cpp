#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector <int> result;
    while (left <= right && top <= bottom) {
        for (int i=left; i<=right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        for (int i=top; i<=bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (top > bottom) break;
        for (int i=right; i>=left; i--) {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;
        if (left > right) break;
        for (int i=bottom; i>=top; i--) {
            result.push_back(matrix[i][left]);
        }
        left++;
    }
    for (int a: result) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}