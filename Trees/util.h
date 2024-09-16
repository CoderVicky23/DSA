#ifndef TREE_H
#define TREE_H

# include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node * left;
    Node * right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {};
};

Node * createTree(const vector <int>& nums);

void inOrder(Node* root);

void postOrder(Node* root);

void preOrder(Node* root);

void levelOrder(Node* root);

int treeHeight(Node* root);

int treeMaxWidth(Node* root);

bool balancedTree(Node* root);

int treeDiameter(Node* root);

int maxPathSum(Node* root);

#endif