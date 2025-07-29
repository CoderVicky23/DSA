#include <bits/stdc++.h>
using namespace std;

bool isValid(string& s, string next, int k) {
    int i = 0, count = 0;
    for (char& ch: s) {
        if (next[i] == ch) {
            i++;
            if (i == next.length()) {
                count++;
                if (count == k) return 1;
            }
        }
    }
    return 0;
}

string longestSubSequence(string& s, int k) {
    unordered_map<char, int> hash;
    for (char& ch: s) {
        hash[ch]++;
    }
    // bfs
    string curr = "";
    queue <string> q;
    q.push(curr);
    string res;

    while (!q.empty()) {
        curr = q.front();
        q.pop();
        string next = curr;
        for (char c='a'; c<='z'; c++) {
            if (hash[c] < k) continue;
            next.push_back(c);
            if (isValid(s, next, k)) {
                res = next;
                q.push(next);
            }
            next.pop_back();
        }
    }
    return res;
}

int main() {
    string s = "letsleetcode";
    int k = 2;
    return 0;
}