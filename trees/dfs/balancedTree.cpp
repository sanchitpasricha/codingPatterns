#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int heightImbalance(TreeNode* node){
    if(node == nullptr){
        return 0;
    }

    int leftHeight = heightImbalance(node -> left);
    int rightHeight = heightImbalance(node -> right);

    if (leftHeight == -1 || rightHeight == -1){
        return -1;
    }
    
    if(abs(leftHeight - rightHeight) > 1){
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
        return heightImbalance(root) != -1;
}


int main() {
    // Create nodes
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);

    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);


/*
           1
         /   \
        2     2
       / \
      3   3
     / \
    4   4

*/
    //

    //

    cout<<isBalanced(root);

    return 0;
}