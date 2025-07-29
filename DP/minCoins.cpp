#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& coins, int sum, int ind) {
    
}

int minCoins(vector<int> &coins, int sum) {
    vector<vector<int>> dp;
    return fun(coins, sum, 0);
}

int main() {
    vector<int> coins = {8, 6, 8, 3};
    int sum = 9;
    cout << minCoins(coins, sum) << endl;
    return 0;
}