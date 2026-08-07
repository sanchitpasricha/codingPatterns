#include<iostream>
#include<deque>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

int widestTree(TreeNode* node){
    if(node == nullptr){
        return 0;
    }

    deque<pair<TreeNode*,int>> dq;
    dq.push_back({node,0});
    int max_width = 0;

    while(!dq.empty()){
        int level_size = dq.size();
        int leftMost = dq.front().second;
        int rightMost = leftMost;

        for(int i=0;i<level_size;i++){
            auto [curr, id] = dq.front();
            dq.pop_front();
            rightMost = id;

            if(curr -> left){
                dq.push_back({curr -> left, 2*id});
            }
            if(curr -> right){
                dq.push_back({curr -> right, 2*id + 1});
            }
        }

        max_width = max(max_width, (rightMost - leftMost + 1));
    }
    return max_width;
}

int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->right = new TreeNode(11);
    root->right->right->left = new TreeNode(14);
/*
           1
          /  \
         /    \
        2      3
       / \      \
      4   5      7
     / \   \    / 
    8   9   11 14
*/

    int max_length = widestTree(root);
    cout<<"Max width of tree :: "<<max_length;
    return 0;

}
