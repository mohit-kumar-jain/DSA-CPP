#include<bits/stdc++.h>
using namespace std;
                   
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
     
vector<int> preOrderTraversal(struct TreeNode* root) {
    vector<int> res;
    if(root == nullptr) return res;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        root = st.top();
        st.pop();
        res.push_back(root->data);
        if(root->right != nullptr) st.push(root->right);
        if(root->left != nullptr) st.push(root->left);
    }
    return res;
}
                   
int main() {
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int>res = preOrderTraversal(root);
    cout << "Pre Order Traversal : " ;
    for(auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}