#include <bits/stdc++.h>
using namespace std;

vector<int> leaders (vector<int>& nums) {
    int n = nums.size();
    int max = nums[n-1];
    vector <int> result = {max};
    for (int i=n-2; i>=0; i--) {
        if (nums[i] > max) {
            max = nums[i];
            result.push_back(max);
        }
    }
    return vector(result.rbegin(), result.rend());
}

int main() {
    vector <int> nums = {1,2,5,3,1,2};
    for (int i: leaders(nums)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}