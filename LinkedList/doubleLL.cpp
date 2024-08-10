#include<bits/stdc++.h>
using namespace std;
struct NODE {
    int val;
    NODE * next;
    NODE * prev;
    NODE (int v, NODE * p, NODE * n) {
        val = v;
        prev = p;
        next = n;
    }
    NODE (int v) {
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
void traversal(NODE * head) {
    NODE * temp = head;
    while (temp) {
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}
void traversalBack(NODE * tail) {
    NODE * temp = tail;
    while (temp) {
        cout << temp->val << "  ";
        temp = temp->prev;
    }
    cout << endl;
}
// create DLL from an array
NODE * createDLL(NODE *& head, NODE *& tail, vector <int>& arr) {
    if (!head) {
        head = new NODE(arr[0], nullptr, nullptr);
        NODE * temp = head;
        NODE * spare = head;
        for (int i=1; i<arr.size(); i++) {
            temp->next = new NODE(arr[i], spare, nullptr);
            spare = temp->next;
            temp = temp->next;
        }
        tail = spare;
    }
    return head;
}
// insert in DLL
void insertAtK(NODE *& head, NODE *& tail, int index, int v) {
    NODE * temp = head;
    int i = 0;
    while (temp) {
        if (i == index) {
            temp->next = new NODE(v, temp, temp->next);
            break;
        }
        temp = temp->next;
        i++;
    }
}
int main()
{
    vector <int> arr = {1,2,3,4,5,6,7,8,9};
    NODE * head = nullptr;
    NODE * tail = nullptr;
    createDLL(head, tail, arr);
    insertAtK(head, tail, 3, 0);
    traversal(head);
    traversalBack(tail);
    return 0;
}