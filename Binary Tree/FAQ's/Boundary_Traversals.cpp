#include<bits/stdc++.h>
using namespace std;
                   
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};    
bool isLeaf(TreeNode* root) {
    if(!root->left && !root->right) return true;
    else return false;
}               

void addLeft(TreeNode* root, vector<int>& res){
    TreeNode* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = (curr->right);
    }
}

void addLeaves(TreeNode* root, vector<int>& res){
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if((root->left)) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

void addRight(TreeNode* root, vector<int>& res){
    TreeNode* curr = root->right;
    vector<int> temp;
    while(curr) {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = (curr->right);
    }
    for (int i = temp.size() - 1; i >= 0 ; --i) 
    {
        res.push_back(temp[i]);
    }
}

vector<int> boundaryTraversals(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) return ans;
    if(!isLeaf(root))  ans.push_back(root->data);
    addLeft(root, ans);
    addLeaves(root, ans);
    addRight(root, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> ans = boundaryTraversals(root);
    cout << "Boundary Traversal of Tree : ";
    for(int it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}