#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node * left;
    node * right;
    node (int d) {
        data = d;
    }
};
void preOrder(node * root) {
    stack <node *> sk;
    sk.push(root);
    node * temp = nullptr;
    while (!sk.empty()) {
        temp = sk.top();
        sk.pop();
        if (temp->right) sk.push(temp->right);
        if (temp->left) sk.push(temp->left);
        cout << temp->data << " ";
    }
}
void postOrder(node * root) {
    stack <node *> sk1;
    stack <node *> sk2;
    sk1.push(root);
    node * temp = root;
    while (!sk1.empty()) {
        temp = sk1.top();
        sk1.pop();
        sk2.push(temp);
        if (temp->left) sk1.push(temp->left);
        if (temp->right) sk1.push(temp->right);
    }
    while (!sk2.empty()) {
        cout << sk2.top() -> data << " ";
        sk2.pop();
    }
}
void inOrder(node * root) {
    stack <node*> stak;
    node * temp = root;
    vector <int> inorder;
    while (1) {
        if (temp != nullptr) {
            stak.push(temp);
            temp = temp->left;
        } else {
            if (stak.empty() == true) break;
            temp = stak.top();
            stak.pop();
            inorder.push_back(temp->data);
            temp = temp->right;
        }
    }
}

int main()
{
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);
    // root->right->right->right->right = new node(10);
    // root->right->right->right->right->right = new node(11);
    cout << "Pre Order Traversal" << endl;
    preOrder(root);
    cout << "\n";
    cout << "Post Order Traversal" << endl;
    postOrder(root);
    cout << "\n";
    cout << "In order traversal" << endl;
    inOrder(root);
    cout << "\n";
    return 0;
}