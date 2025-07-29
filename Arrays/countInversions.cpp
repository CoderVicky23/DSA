#include <bits/stdc++.h>
using namespace std;

int result = 0;

int merge(vector<int>& nums, int start, int mid, int end) {
    vector<int> a;
    int i = start;
    int j = mid;
    int count = 0;
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            a.push_back(nums[i]);
            i++;
        } else {
            count++;
            a.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid) {
        a.push_back(nums[i]);
        i++;
    }
    while (j <= end) {
        a.push_back(nums[j]);
        j++;
    }
    int n = a.size();
    for (int i=start, j=0; i<end && j<n; i++, j++) {
        nums[i] = a[j];
    }
    a.clear();
    return count;
}

int mergeSort(vector<int>& nums, int start, int end) {
    if (start >= end) return 0;
    else {
        int count = 0;
        int mid = (start + end)/2;
        count += mergeSort(nums, start, mid);
        count += mergeSort(nums, mid + 1, end);
        count += merge(nums, start, mid, end);
        return count;
    }
}

int inversions(vector<int>& nums) {
    int start = 0, end = nums.size();
    return mergeSort(nums, start, end-1);
}

int main() {
    vector<int> nums = {5, 3, 2, 4, 1};
    cout << inversions(nums) << endl;
    return 0;
}