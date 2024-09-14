#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
    node(): data(0), left(nullptr), right(nullptr) {};
    node(int val): data(val), left(nullptr), right(nullptr){};
};
// recursive approach;
int depth(node * root) {
    if (!root) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

// level order approach;
int depth_level_order(node * root) {
    queue <node *> q;
    if (root) q.push(root);
    int depth = 0;
    node * temp = nullptr;
    while (!q.empty()) {
        depth++;
        int k = q.size();
        while (k--) {
            temp = q.front();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
        }
    }
    return depth;
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
    root->right->right->right->right = new node(10);
    root->right->right->right->right->right = new node(11);
    cout << depth(root) << endl;
    cout << depth_level_order(root) << endl;
    return 0;
}