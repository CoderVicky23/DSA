#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> nums = {2, 4, -2, 3};
    int n = nums.size();
    double prefix = 1;
    double suffix = 1;
    double maxi = INT_MIN;
    for (int i=0; i<n; i++) {
        prefix *= nums[i];
        suffix *= nums[n-i-1];
        maxi = max(maxi, max(prefix, suffix));
        if (!prefix) prefix = 1;
        if (!suffix) suffix = 1;
    }
    cout << (int) maxi << endl;
    return 0;
}