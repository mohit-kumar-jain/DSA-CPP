#include<bits/stdc++.h>
using namespace std;
                   
struct TreeNode{
    int data;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// T.C -> O(3N), S.C -> O(3N).
vector<vector<int>> PreInPost(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    stack<pair<TreeNode* , int>> st;
    st.push({root,1});
    vector<int> pre,post,in;
    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL) {
                st.push({it.first->left,1});
            }
        } else if(it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL) {
                st.push({it.first->right,1});
            }
        } else{
            post.push_back(it.first->data);
        }
    }
    res.push_back(pre);
    res.push_back(in);
    res.push_back(post);
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
    vector<vector<int>> res = PreInPost(root);
    for(auto it : res) {
        for(auto row : it) {
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}