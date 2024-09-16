#include "tree.h"
#include <iostream>
#include <queue>

// Function definition that creates a binary tree from a vector
TreeNode* createTree(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;

    // Create the root of the tree
    TreeNode* root = new TreeNode(nums[0]);

    // Queue to hold the tree nodes for level-wise construction
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < nums.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Create the left child
        if (i < nums.size()) {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
            i++;
        }

        // Create the right child
        if (i < nums.size()) {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
            i++;
        }
    }

    return root;
}

// Function definition for In-Order traversal
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}
