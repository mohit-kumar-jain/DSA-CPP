#include<bits/stdc++.h>
using namespace std;
                   
struct TreeNode{
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int x){
        data = x;
    }
};                   
    
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    map<int, map<int, multiset<int>>> mpp;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        mpp[x][y].insert(node->data);
        if(node->left) {
            q.push({node->left,{x - 1, y + 1}});
        }
        if(node->right) {
            q.push({node->right,{x + 1, y + 1}});
        }
    }
    for(auto p : mpp){
        vector<int> col;
        for(auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        res.push_back(col);
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans =  verticalTraversal(root);
    for(auto it : ans){
        for(auto c : it) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}