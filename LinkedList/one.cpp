#include <iostream>
#include <vector>
using namespace std;
struct NODE {
    int data;
    NODE * next;
    // struct constructor
    NODE(int d, NODE * n){
        data = d;
        next = n;
    }
    NODE (int d) {
        data = d;
        next = nullptr;
    }
};
NODE * convertToLL(vector <int>& arr) {
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
        cout << mover->data << endl;
        mover = mover->next;
    }
}

int lengthOfLL(NODE * head) {
    int count = 0;
    NODE * temp = head;
    while (temp) {
        count++;
        temp = temp -> next;
    }
    return count;
}

int checkIfPresent(NODE * head, int value) {
    NODE * temp = head;
    int index = 0;
    while (temp) {
        if (temp->data == value) {
            return index;
        } else {
            temp = temp -> next;
            index++;
        }
    }
    return -1;
}

int main() {
    vector <int> arr = {1, 5, 3, 2, 9, 8, 6};
    NODE * head = convertToLL(arr);
    traversal(head);
    return 0;
}