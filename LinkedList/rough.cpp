#include<bits/stdc++.h>
using namespace std;
struct NODE {
    int val;
    NODE * next;
    NODE (int v) {
        val = v;
        next = nullptr;
    }
};
NODE * fun(NODE *& head) {
    head = new NODE(6);
    cout << head << endl;
    return head;
}
int main()
{
    NODE * head = new NODE(5);
    cout << head << endl;
    fun(head);
    cout << head << endl;
    return 0;
}