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
void inOrder(Node * root) {
    if (root->left) inOrder(root->left);
    cout << root->val << " ";
    if (root->right) inOrder(root->right);
}

// preOrder traversal
void preOrder(Node * root) {
    cout << root->val << " ";
    if (root->left) preOrder(root->left);
    if (root->right) preOrder(root->right);
}

// postOrder traversal
void postOrder(Node * root) {
    if (root->left) postOrder(root->left);
    if (root->right) postOrder(root->right);
    cout << root->val << " ";
}

// levelOrder traversal
void levelOrder(Node * root) {
    queue <Node *> q;
    q.push(root);
    Node * temp = nullptr;
    while (!q.empty()) {
        int k = q.size();
        while (k--) {
            temp = q.front();
            cout << temp->val << " ";
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    cout << endl;
}

int treeHeight(Node * root) {
    if (!root) return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

int treeMaxWidth(Node * root) {
    queue <Node *> q;
    q.push(root);
    Node * temp = nullptr;
    int res = 0;
    while (!q.empty()) {
        int k = q.size();
        res = max(res, k);
        while (k--) {
            temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return res;
}

int driverBalancedTree(Node * root) {
    if (!root) return 0;
    int lh = driverBalancedTree(root->left);
    if (lh == -1) return -1;
    int rh = driverBalancedTree(root->right);
    if (rh == -1) return -1;
    if (abs(lh-rh) > 1) return -1;
    return 1 + max(lh, rh);
}   

bool balancedTree(Node* root) {
    return (driverBalancedTree(root) > 0);
}

int td(Node* root, int& maxi) {
    if (!root) return 0;
    int l = td(root->left, maxi);
    int r = td(root->right, maxi);
    maxi = max(maxi, l+r);
    return 1 + max(l,r);
}

int treeDiameter(Node* root) {
    int maxi = 0;
    td(root, maxi);
    return maxi;
}

int mp(Node* root, int& maxi) {
    if (!root) return 0;
    int l = mp(root->left, maxi);
    int r = mp(root->right, maxi);
    maxi = max(maxi, root->val + l + r);
    return root->val + max(l, r);
}

int maxPathSum(Node* root) {
    int maxi = 0;
    mp(root, maxi);
    return maxi;
}

int main() {
    vector <int> nums = {0, 1, 2, 3, NULL, NULL, 4, NULL, 5, 6, NULL, 7, 8, 9, 10};
    vector <int> num = {1, 2, 3, 4, 5, 6, 7, 8, NULL, 9, 10, NULL, NULL, NULL, 11, NULL, NULL, NULL, NULL, NULL, NULL, 12};
    Node * root = createTree(num);
    // inOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;
    // preOrder(root);
    // cout << endl;
    // levelOrder(root);
    // cout << treeHeight(root) << endl;
    // cout << treeMaxWidth(root) << endl;
    // cout << balancedTree(root) << endl;
    // cout << treeDiameter(root) << endl;
    cout << maxPathSum(root) << endl;
    return 0;
}