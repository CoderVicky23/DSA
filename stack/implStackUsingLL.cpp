#include <bits/stdc++.h>
using namespace std;

struct stackNODE {
    int val;
    stackNODE * next;

    stackNODE (int x) : val(x), next(nullptr) {}
};

void push(int x, stackNODE *& head) {
    stackNODE * newNode = new stackNODE(x);
    newNode->next = head;
    head = newNode;
}

int pop(stackNODE *& head) {
    if (!head) return -1;
    int k = head->val;
    stackNODE * temp = head;
    head = head->next;
    delete temp;
    return k;
}

int main() {
    stackNODE * head = nullptr;
    vector<vector<int>> inst = {{1, 2}, {1, 3}, {2}, {1, 4}, {2}};
    for (auto& i: inst) {
        if (i[0] == 1) {
            push(i[1], head);
        } else {
            cout << pop(head) << endl;
        }
    }
    return 0;
}