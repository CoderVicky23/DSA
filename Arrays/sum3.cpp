#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {-1, 0, 1, 2, -1, 4};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector <vector <int>> result;
    for (int i=0; i<n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int m = arr[i] + arr[j] + arr[k];
            if (m == 0) {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j-1]) j++;
                while (j < k && arr[k] == arr[k+1]) k--;
            } else if (m > 0) {
                k--;
                while (j < k && arr[k] == arr[k+1]) k--;
            } else {
                j++;
                while (j < k && arr[j] == arr[j-1]) j++;
            }
        }
    }
    for (vector<int>& a: result) {
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
    return 0;
}