#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this -> val = val;
        left = nullptr;
        right = nullptr;
    }
};

bool checkBounds(TreeNode* node, int upperBound, int lowerBound){
    if(node == nullptr){
        return true;
    }
    if(!(node->val > lowerBound && node -> val < upperBound)){
        return false;
    }
    if(!(checkBounds(node->left, node -> val, lowerBound))){
        return false;
    }
    return checkBounds(node -> right, upperBound, node -> val);

}

bool isValidBST(TreeNode* root){
    checkBounds(root, INT_MIN, INT_MAX);
}

int main(){
    TreeNode* root = new TreeNode(5);

    root -> left = new TreeNode(2);
    root -> right = new TreeNode(7);

    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(6);

    root -> right -> left  = new TreeNode(7);
    root -> right -> right = new TreeNode(9);

    string valid = isValidBST(root) ? "Valid" : "Not valid";
    cout<<"The given BST is : "<<valid;

/*
         5
       /   \
      2     7
     / \   / \
    1   6 7   9
*/
    return 0;

}