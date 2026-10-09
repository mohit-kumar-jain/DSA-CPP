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

// Brute. T.C -> O(N*N), S.C -> O(N).
// int maxHeight(TreeNode* root){
//     if(root == nullptr) return 0;
//     int lh = maxHeight(root->left);
//     int rh = maxHeight(root->right);
//     return 1 + max(lh, rh);
// }

// int maxDiameter(TreeNode* root) {
//     if(root == nullptr) return 0;
//     int lh = maxHeight(root->left);
//     int rh = maxHeight(root->right);
//     int maxi = 0;
//     maxi = max(maxi, lh + rh);
//     maxDiameter(root->left);
//     maxDiameter(root->right);
//     return maxi;
// }


// Optimal.  T.C -> O(N) , S.C -> O(N).

int maxDepth(TreeNode* root, int& diameter) {
    if (root == nullptr) return 0;
    int lh = maxDepth(root->left, diameter);
    int rh = maxDepth(root->right,diameter);
    diameter =  max(lh+rh, diameter);
    return max(lh, rh) + 1;
}

int maxDiameter(TreeNode* root) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}
                   
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    cout <<"Maximum Diameter of the Binary Tree is : " << maxDiameter(root) << endl;
    return 0;
}