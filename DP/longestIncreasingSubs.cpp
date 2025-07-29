#include <bits/stdc++.h>
using namespace std;

int n;

int solve(vector<int>& nums, int i) {
    if (i >= n) return 0;
    int skip, take;
    if (i > 0) {
        if (nums[i-1] > nums[i]) {
            skip = solve(nums, i+1);
        } else {
            take = 1 + solve(nums, i+1);
        }
        return max(skip, take);
    }
    else {
        take = 1 + solve(nums, i+1);
        skip = solve(nums, i+1);
        return max(skip, take);
    }
}

int longestIncreasingSubs(vector<int>& nums) {
    n = nums.size();
    return solve(nums, 0);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << longestIncreasingSubs(arr) << endl;
    return 0;
}