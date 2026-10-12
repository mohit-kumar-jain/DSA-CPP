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

vector<vector<int>> printZigZag(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool LeftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> res(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            int index = (LeftToRight) ? i : (size - i - 1);
            res[index] = node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        LeftToRight = !(LeftToRight);
        ans.push_back(res);
    }
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
    vector<vector<int>> ans = printZigZag(root);
    cout << "Zig Zag Pattern of Tree : " << endl;
    for(auto it : ans) {
        for(auto row : it) {
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}