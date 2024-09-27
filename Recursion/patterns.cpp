#include<bits/stdc++.h>
using namespace std;

// printing subsequences with sum = k
void fun(vector <int>& nums, int k, int i, int& sum, vector <int>& arr) {
    if (i >= nums.size() && sum == k) {
        for (int j: arr) {
            cout << j << " ";
        }
        cout << endl;
        return;
    } else if (i >= nums.size()) return;
    sum += nums[i];
    arr.push_back(nums[i]);
    fun(nums, k, i+1, sum, arr);
    sum -= nums[i];
    arr.pop_back();
    fun(nums, k, i+1, sum, arr);
}
void printSubs(vector <int>& nums, int k) {
    vector <int> arr;
    int sum = 0;
    fun(nums, k, 0, sum, arr);
}

// count subsequences with sum = k
int func(int i, int& sum, int k, vector <int>& nums) {
    if (sum > k) return 0;
    if (i >= nums.size()) {
        if (sum == k) {
            return 1;
        }
        return 0;
    }
    sum += nums[i];
    int a = func(i+1, sum, k, nums);
    sum -= nums[i];
    int b = func(i+1, sum, k, nums);
    return a + b;
}

void countSubs(vector <int>& nums, int k) {
    int sum = 0;
    cout << func(0, sum, k, nums) << endl;
}

int main()
{
    vector <int> nums = {2, 1, 4, 3, 2};
    // printSubs(nums, 4);
    countSubs(nums, 3);
    return 0;
}