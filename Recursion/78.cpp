#include<bits/stdc++.h>
using namespace std;

void fun(vector <int>& nums, int ind, vector <vector <int>>& result, vector <int>& ds) {
    if (ind >= nums.size()) {
        result.push_back(ds);
        return;
    }

    ds.push_back(nums[ind]);
    fun(nums, ind+1, result, ds);
    ds.pop_back();
    fun(nums, ind+1, result, ds);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector <vector <int>> result;
    vector <int> ds;
    int ind = 0;
    fun(nums, ind, result, ds);
    return result;
}

int main()
{
    vector <int> nums = {1,2,3};
    for (auto i: subsets(nums)) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}