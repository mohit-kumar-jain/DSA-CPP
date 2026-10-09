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
    if(lh == -1) return -1;

    int rh = maxDepth(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    return maxDepth(root) != -1;
}
                   
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout <<"Given Binary Tree is Balanced? : " ;
    isBalanced(root)? cout << "True" :  cout  << "False" << endl;
    return 0;
}