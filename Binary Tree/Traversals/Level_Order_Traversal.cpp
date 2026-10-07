#include<bits/stdc++.h>
using namespace std;
                   
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> res;
    if(root == nullptr) return{{}};
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> list;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            list.push_back(node->data);
        }
        res.push_back(list);
        
    }
    return res;
}
                   
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(13);
    cout << "Level Order Traversal : " << endl;
    vector<vector<int>> res = levelOrderTraversal(root);
    for(auto it : res) {
        for(auto row : it) {
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}