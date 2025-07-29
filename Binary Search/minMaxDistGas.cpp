#include <bits/stdc++.h>
using namespace std;

long double minMaxDist(vector<int>& gas, int k) {
    int n = gas.size();
    vector<pair<long double,int>> arr;
    arr.push_back({0, 0});
    priority_queue <pair<long double,int>> maxHeap;
    for (int i=1; i<n; i++) {
        long double gap = gas[i] - gas[i-1];
        arr.push_back({gap, 1});
        maxHeap.push({gap, i});
    }
    for (int i=0; i<k; i++) {
        auto [curr_max_dist, ind] = maxHeap.top();
        maxHeap.pop();
        long double diff_initial = arr[ind].first;
        int partitions = arr[ind].second + 1;
        long double diff_new = diff_initial / partitions;
        arr[ind].second = partitions;
        maxHeap.push({diff_new, ind});
    }
    long double result = maxHeap.top().first;
    return round(result * 100.0)/100.0;
}

long double minMaxDis(vector<int>& gas, int k) {
    int n = gas.size();
    vector<int> arr (n, 0);
    for (int i=0; i<k; i++) {
        long double maxSection = -1;
        int maxInd = -1;
        for (int j=0; j<n-1; j++) {
            long double diff = gas[j+1] - gas[j];
            long double partn = diff / ((long double) (arr[j] + 1));
            if (partn > maxSection) {
                maxSection = partn;
                maxInd = j;
            }
        }
        arr[maxInd]++;
    }
    long double res = 0;
    for (int i=0; i<n-1; i++) {
        long double partn = gas[i+1] - gas[i];
        res = max(res, partn/((long double) (arr[i] + 1)));
    }
    return res;
}

int main() {
    vector<int> gas = {1, 13, 17, 23};
    // vector<int> gas = {1,2,3,4,5,6,7,8,9,10};
    int k = 5;
    cout << "start" << endl;
    cout << minMaxDist(gas, k) << endl;
    cout << "finish" << endl;
    return 0;
}