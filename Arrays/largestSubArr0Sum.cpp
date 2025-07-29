#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> arr = {-31, -48, -90, 54, 20, 95, 6, -86, 22};
    int n = arr.size();
    unordered_map <int, int> hash;
    int prefix = 0;
    int maxi = 0;
    for (int i=0; i<n; i++) {
        prefix += arr[i];
        if (prefix == 0) {
            maxi = max(maxi, i + 1);
        }
        else if (hash.find(prefix) == hash.end()) {
            hash[prefix] = i;
        } else {
            maxi = max(maxi, i - hash[prefix]);
        }
    }
    for (auto i: hash) {
        cout << i.first << " " << i.second << endl;
    }
    cout << maxi << endl;
    return 0;
}