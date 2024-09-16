#ifndef TREE_H
#define TREE_H

#include <vector>

// Definition of the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function declaration that creates a binary tree from a vector
TreeNode* createTree(const std::vector<int>& nums);

// Function declaration for In-Order traversal
void printInOrder(TreeNode* root);

#endif  // TREE_H
