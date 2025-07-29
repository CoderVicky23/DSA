#include <bits/stdc++.h>
using namespace std;

bool isStraightHand(vector<int>& hand, int group) {
    if (hand.size()%group != 0) return false;
    map <int, int> mp;
    for (int i: hand) mp[i]++;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int card = it->first;
        int freq = it->second;
        if (freq == 0) continue;
        for (int j=0; j<group; j++) {
            int curr = card + j;
            if (mp[curr] < freq) return false;
            mp[curr] -= freq;
        }
    }
    return true;
}

int main() {
    vector <int> hand = {1, 2,3,6,2,3,4,7,8};
    int group = 3;
    cout << isStraightHand(hand, group) << endl;
    return 0;
}