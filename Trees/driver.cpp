#include "util.h"
#include <bits/stdc++.h>

int main() {
    vector <int> nums = {0, 1, 2, 3, NULL, NULL, 4, NULL, 5, 6, NULL, 7, 8, 9, 10};
    vector <int> num = {1, 2, 3, 4, 5, 6, 7, 8, NULL, 9, 10, NULL, NULL, NULL, 11, NULL, NULL, NULL, NULL, NULL, NULL, 12};
    Node * root = createTree(num);
    inOrder(root);
    return 0;
}