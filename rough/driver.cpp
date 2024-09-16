#include "tree.h"
#include <iostream>

int main() {
    // Example input vector
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    // Create the binary tree from the vector
    TreeNode* root = createTree(nums);

    // Print the binary tree using In-Order Traversal
    std::cout << "In-Order Traversal of the Tree: ";
    printInOrder(root);  // Now calling the function from tree.cpp
    std::cout << std::endl;

    return 0;
}
