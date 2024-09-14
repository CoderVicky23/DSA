#include<bits/stdc++.h>

using namespace std;
struct node {
    int data;
    node * left;
    node * right;
    node (int d) {
        data = d;
        left = right = nullptr;
    }
};

void preOrder(node * root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node * root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node * root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(node * root) {
    queue <node *> qu;
    qu.emplace(root);
    node * temp = root;
    while (!qu.empty()) {
        temp = qu.front();
        cout << temp -> data << " ";
        qu.pop();
        if (temp->left != nullptr) qu.emplace(temp->left);
        if (temp->right != nullptr) qu.emplace(temp->right);
    }
}
int balancedBT(node * root) {
    if (root == nullptr) return 0;
    int left = balancedBT(root->left);
    int right = balancedBT(root->right);
    if (right == -1 || left == -1) return -1;
    if (abs(left-right) > 1) return -1;
    else return 1 + max(left, right);
}

// diameter of binary tree
int diameter(node * root, int& maxi) {
    if (!root) return 0;
    int l = diameter(root->left, maxi);
    int r = diameter(root->right, maxi);
    maxi = max(l+r, maxi);
    return max(l, r) + 1;
}

// width of a binary tree
int width(node * root) {
    node * temp = root;
    stack <node *> s;
    s.push(root);
    int maxi = 0;
    while (1) {
        int k = s.size();
        maxi = max(k, maxi);
        while (k--) {
            temp = s.top();
            s.pop();
            if (temp->left) s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        if (s.empty()) break;
    }
    return maxi;
}

// max path sum
int maxPath(node * root, int& maxi) {
    if (!root) return 0;
    int l = max(0, maxPath(root->left, maxi));
    int r = max(0, maxPath(root->right, maxi));
    maxi = max(maxi, root->data + l + r);
    return root->data + max(l, r);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
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
    // cout << "PreOrder Traversal" << endl;
    // preOrder(root);
    // cout << "\n";
    // cout << "InOrder Traversal" << endl;
    // inOrder(root);
    // cout << "\n";
    // cout << "PostOrder Traversal" << endl;
    // postOrder(root);
    // cout << "\n";
    // cout << "Level Order Traversal" << endl;
    // levelOrder(root);
    // balanced binary tree
    // cout << balancedBT(root) << endl;
    // cout << "\n";
    // int maxi = 0;
    // diameter(root, maxi);
    // cout << maxi << endl;
    // cout << width(root) << endl;
    int maxi = 0;
    maxPath(root, maxi);
    cout << maxi << endl;
    return 0;
}