#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    cout<<root -> val<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inorder(root -> left);
    cout<<root -> val<<" ";
    inorder(root -> right);
}

void postorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> val<<" ";
}

/*
        1
      /   \
     2     3
    / \   /
   4   5 6
*/
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}