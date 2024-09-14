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
void traversal(vector <int> a) {
    for (int i: a) {
        cout << i << " ";
    }
    cout << endl;
}
void postOrder(node * head) {
    node * temp = head;
    stack <node*> stak1;
    stack <node*> stak2;
    vector <int> result;
    if (head) stak1.emplace(head);
    while (!stak1.empty()) {
        temp = stak1.top();
        stak1.pop();
        stak2.push(temp);
        if (temp->left) stak1.push(temp->left);
        if (temp->right) stak1.push(temp->right);
    }
    while (!stak2.empty()) {
        result.push_back(stak2.top()->data);
        stak2.pop();
    }
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
}
void inorder(node * head) {
    stack <node*> stak;
    vector <int> result;
    node * temp = head;
    while (1) {
        if (temp) {
            stak.push(temp);
            temp = temp->left;
        } else {
            if (stak.empty()) break;
            temp = stak.top();
            stak.pop();
            result.push_back(temp->data);
            temp = temp->right;
        }
    }
    for (int i: result) {
        cout << i << " ";
    }
    cout << endl;
}
void threeTraversals(node * head) {
    node * temp = head;
    vector <int> inorder;
    vector <int> postorder;
    vector <int> preorder;
    stack <pair <node *, int>> stak;
    stak.push({temp, 1});
    while (!stak.empty()) {
        if (stak.top().second == 1) {
            temp = stak.top().first;
            preorder.push_back(temp->data);
            stak.top().second += 1;
            if (temp->left) stak.push({temp->left, 1});
        } else if (stak.top().second == 2) {
            temp = stak.top().first;
            inorder.push_back(temp->data);
            stak.top().second += 1;
            if (temp->right) stak.push({temp->right, 1});
        } else if (stak.top().second == 3) {
            temp = stak.top().first;
            postorder.push_back(temp->data);
            stak.pop();
        }
    }
    cout << "inorder: ";
    traversal(inorder);
    cout << "postorder: ";
    traversal(postorder);
    cout << "preorder: ";
    traversal(preorder);
}
void levelOrder(node * root) {
    node * temp = root;
    queue <node *> qu;
    qu.push(root);
    vector <vector <int>> result;
    while (!qu.empty()) {
        vector <int> sub;
        int i = qu.size();
        while (i--) {
            temp = qu.front();
            qu.pop();
            sub.push_back(temp->data);
            if (temp->left) qu.push(temp->left);
            if (temp->right) qu.push(temp->right);
        }
        result.push_back(sub);
    }
    for (auto i: result) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
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
    // cout << "Pre Order Traversal" << endl;
    // preOrder(root);
    // cout << "\n";
    // cout << "Post Order Traversal" << endl;
    // postOrder(root);
    // cout << "\n";
    // cout << "Three order traversals are: " << endl;
    // threeTraversals(root);
    cout << "Level order traversal: " << endl;
    levelOrder(root);
    // cout << "\n";
    return 0;
}