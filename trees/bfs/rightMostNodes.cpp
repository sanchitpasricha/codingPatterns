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

vector<int> rightMost(TreeNode* root){
    if(root == nullptr){
        return {};
    }
    vector<int> ans;
    deque<TreeNode*> dq;
    dq.push_back(root);

    while(!dq.empty()){
        int levelSize = dq.size();

        for(int i=0;i<levelSize;i++){
            TreeNode* node = dq.front();
            dq.pop_front();
            if(node -> left){
                dq.push_back(node -> left);
            }
            if(node -> right){
                dq.push_back(node -> right);
            }

            if(i == levelSize - 1){
                ans.push_back(node -> val);
            }
        }
    }

    return ans;

}

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(20);

    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(30);
/*
           1
         /   \
        2     10
       / \
      3   20
     / \
    4   30
*/

    vector<int> ans = rightMost(root);

    for(auto x : ans){
        cout<<x<<" ";
    }

    return 0;
}