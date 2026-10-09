#include<bits/stdc++.h>
using namespace std;
                   
struct TreeNode{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};     

int maxDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return max(lh, rh) + 1;
}
                   
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout <<"Maximum Depth of the given Binary Tree is : " <<  maxDepth(root) << endl;
    return 0;
}