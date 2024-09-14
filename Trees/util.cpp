#include "util.h"

// create tree function from vector
Node * createTree(const vector <int>& nums) {
    if (nums.empty()) return nullptr;
    Node * root = new Node(nums[0]);
    Node * temp = nullptr;
    queue <Node *> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        temp = q.front();
        q.pop();
        if (nums[i]) {
            temp->left = new Node(nums[i]);
            q.push(temp->left);
        }
        i++;
        if (i < nums.size() && nums[i]) {
            temp->right = new Node(nums[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

// inorder traversal
