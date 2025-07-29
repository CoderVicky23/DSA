#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {1, 2, 2, 4, 5, 3, 3, 1};
    int n = arr.size();
    int count = 0;
    int start = 0;
    vector <vector <int>> result;
    while (start < n) {
        int end = start;
        int dir = 0; // direction: 1 for increasing -1 for decreasing and 0 for constant
        while (end + 1 < n && arr[end] == arr[end+1]) {
            // modification funciton
            count++;
            result.push_back({end});
            start = ++end;
        }
        // setting direction
        if (end + 1 < n) {
            dir = (arr[end] < arr[end+1]) ? 1 : -1;
        }
        // expanding while the direction remains the same
        while (end + 1 < n && ((dir == 1 && arr[end] < arr[end+1]) || (dir == -1 && arr[end] > arr[end+1]))) {
            end++;
        }
        int k = (end - start + 1);
        count += (k*(k+1))/2;
        start = end + 1;
    }
    cout << count << endl;
    // for (auto i: result) {
    //     for (int j: i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}