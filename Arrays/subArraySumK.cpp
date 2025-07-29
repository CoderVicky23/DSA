#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int n = nums.size();
    int count = 0;
    int prefix = 0;
    unordered_map <int, int> hash;
    for (int i=0; i<n; i++) {
        prefix += nums[i];
        int diff = prefix - k;
        count += hash[diff];
        hash[prefix]++;
    }
    cout << count << endl;
    return 0;
}