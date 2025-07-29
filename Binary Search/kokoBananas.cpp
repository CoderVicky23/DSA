#include <bits/stdc++.h>
using namespace std;

int kokoBanana(vector <int>& piles, int hours) {
    int n = piles.size();
    int l = 1;
    int h = INT_MIN;
    for (int& i: piles) {
        if (i > h) h = i;
    }
    int res = 1;
    while (l <= h) {
        int i = l + (h - l)/2;
        int count = 0;
        for (int j : piles)
        {
            count += ceil((float) j/i);
        }
        if (count <= hours) {
            res = i;
            h = i - 1;
        } else {
            l = i + 1;
        }
    }
    return res;
}


// brute force solution
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int n = piles.size();
    int h = 4;
    cout << kokoBanana(piles, h) << endl;
    // int smallest = INT_MAX;
    // int largest = INT_MIN;
    // for (int i: piles) {
    //     if (i > largest) largest = i;
    //     if (i < smallest) smallest = i;
    // }
    // int i = smallest;
    // for (; i <= largest; i++)
    // {
    //     int count = 0;
    //     for (int j : piles)
    //     {
    //         do {
    //             count++;
    //             j -= i;
    //         } while (j > 0);
    //     }
    //     if (count <= h)
    //         break;
    // }
    // cout << i << endl;
    return 0;
}