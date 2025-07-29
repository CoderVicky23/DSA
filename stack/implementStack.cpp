#include <bits/stdc++.h>
using namespace std;



class MyStack
{
private:
    int arr[1000];
    int top;

    public:
    MyStack(){top=-1;}
    // int pop();
    // void push(int);
    void push(int x) {
        int * arr = this->arr;
        arr[++(this->top)] = x;
    }

    int pop() {
        int * arr = this->arr;
        int k = arr[this->top];
        (this->top)--;
        return k;
    }
};

int main() {
    vector<int> inst = {1, 2, 1, 3, 2, 1, 4, 2};
    int n = inst.size();
    MyStack* obj = new MyStack();
    for (int i=0; i<n; i++) {
        if (inst[i] == 1) {
            obj->push(inst[i+1]);
            i++;
        } else {
            int r = obj->pop();
            cout << r << endl;
        }
    }
    return 0;
}