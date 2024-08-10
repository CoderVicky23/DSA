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

NODE * insertNode(int v, NODE * head) {
    NODE * temp = head;
    NODE * prev = temp;
    while (temp) {
        if (temp->data > v) {
            prev->next = new NODE(v);
            prev->next->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    NODE * head = nullptr;
    vector <int> arr = {1,2,3,5,6,7};
    for (int i=0; i<arr.size(); i++) {
        head = createNode(arr[i], head);
    }
    traversal(head);
    // insert 8 after 3
    head = insertNode(4, head);
    traversal(head);
    return 0;
}