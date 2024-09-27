#include<bits/stdc++.h>
using namespace std;

void insert(int element, stack <int>& s) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    if (top <= element) {
        insert(element, s);
    }
    s.push(top);
}

stack <int> sortStack(stack <int>& s) {
    if (s.empty()) return s;
    int top = s.top();
    s.pop();
    sortStack(s);
    insert(top, s);
    return s;
}

int main()
{
    stack <int> s;
    int arr[] = {7, 6, 5, 4, 1, 2, 3, 10, 9, 8};
    for (int i=0; i<sizeof(arr)/sizeof(int); i++) {
        s.push(arr[i]);
    }
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}