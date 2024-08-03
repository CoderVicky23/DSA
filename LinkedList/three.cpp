#include<bits/stdc++.h>
using namespace std;
struct NODE {
    int data;
    NODE * next;
    NODE(int d, NODE * n) {
        data = d;
        next = n;
    }
    NODE (int d) {
        data = d;
    }
};

void traversal(NODE * head) {
    NODE * mover = head;
    while (mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

NODE * createNode(int d, NODE *& head) {
    if (!head) {
        return new NODE(d);
    }
    NODE * temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new NODE(d);
    return head;
}

int main()
{
    NODE * head = nullptr;
    vector <int> arr = {1,2,3,4,5};
    for (int i=0; i<arr.size(); i++) {
        head = createNode(arr[i], head);
    }
    traversal(head);
    return 0;
}