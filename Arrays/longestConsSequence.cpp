#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {1,2,3,4,7,8,9,10,11,13};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxi = 1;
    int count = 1;
    for (int i=0; i<n-1; i++) {
        if (arr[i] + 1 == arr[i+1]) {
            count++;
        } else {
            maxi = max(maxi, count);
            count = 1;
        }
    }
    cout << maxi << endl;
    return 0;
}