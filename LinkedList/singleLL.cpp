#include<bits/stdc++.h>
using namespace std;
struct NODE {
    int value;
    NODE * next;
    NODE (int val) {
        value = val;
        next = nullptr;
    }
};
// traversing linked list
void traversal(NODE * head) {
    NODE * temp = head;
    while (temp) {
        cout << temp->value << "  ";
        temp = temp->next;
    }
    cout << endl;
}
// creating a linked list from an array
NODE * createLL(NODE * head, int * arr, int n) {
    if (!head && n > 0) {
        NODE * temp = new NODE(arr[0]);
        head = temp;
        for (int i=1; i<n; i++) {
            temp->next = new NODE(arr[i]);
            temp = temp->next;
        }
    }
    else if (head) {
        NODE * temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        int i = 0;
        while (i < n) {
            temp->next = new NODE(arr[i]);
            temp = temp->next;
        }
    }
    return head;
}
// inserting an element at kth index;
NODE * insertAtK(NODE * head, int val, int index) {
    NODE * temp = head;
    if (index == 0) {
        head = new NODE(val);
        head->next = temp;
    } else {
        NODE * prev = temp;
        temp = temp->next;
        int i = 1;
        bool flag = 0;
        while (temp) {
            if (i == index) {
                prev->next = new NODE(val);
                prev->next->next = temp;
                flag = 1;
                break;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (!flag) {
            if (i == index) {
                prev->next = new NODE(val);
            } else {
                cout << "Out of Bounds" << endl;
            }
        }
    }
    return head;
}
NODE * deleteAtK(NODE * head, int index) {
    NODE * temp = head;
    if (index == 0) {
        head = temp->next;
        delete temp;
    } else {
        NODE * prev = head;
        temp = temp->next;
        int i = 1;
        bool flag = 0;
        while (temp) {
            if (index == i) {
                prev->next = prev->next->next;
                delete temp;
                flag = 1;
                break;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
    }
    return head;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    NODE * head = nullptr;
    head = createLL(head, arr, n);
    traversal(head);
    head = insertAtK(head, 8, 5);
    traversal(head);
    head = deleteAtK(head, 3);
    traversal(head);
    return 0;
}