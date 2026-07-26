#include<iostream>
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

TreeNode* invert(TreeNode* root) {
    if (!root){
        return nullptr;
    }
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        if(node -> left){
            st.push(node -> left);
        }

        if(node -> right){
            st.push(node -> right);
        }
    }
    return root;
}


/*
        1
      /   \
     2     3
    / \   /
   4   5 6
*/
void preorder(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    preorder(root);
    cout<<endl;
    invert(root);
    preorder(root);

    return 0;
}