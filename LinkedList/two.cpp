#include<bits/stdc++.h>

using namespace std;

struct NODE {
    int data;
    NODE * next;

    NODE(int d, NODE * n) {
        data = d;
        next = n;
    }
    NODE(int d) {
        data = d;
        next = nullptr;
    }
};

NODE * createLinkedList(vector <int>& arr) {
    NODE * head = new NODE(arr[0]);
    NODE * mover = head;
    for (int i=1; i<arr.size(); i++) {
        NODE * temp = new NODE(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversal(NODE * head) {
    NODE * mover = head;
    while (mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

NODE * removeHead(NODE * head) {
    if (head == NULL) return head;
    NODE * temp = head;
    head = head -> next;
    delete temp;
    return head;
}

NODE * removeTail(NODE * head) {
    NODE * temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    temp->next = nullptr;
    NODE * spare = temp->next;
    delete spare;
    return head;
}

NODE * removeNode(NODE * head, int element) {
    NODE * temp = head;
    NODE * prev = head;
    while (temp) {
        if (temp->data == element) {
            NODE * spare = temp;
            prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector <int> arr = {5, 9, 6, 3, 2, 1};
    NODE * head = createLinkedList(arr);
    traversal(head);
    // head = removeHead(head);
    // head = removeTail(head);
    head = removeNode(head, 2);
    traversal(head);
    return 0;
}