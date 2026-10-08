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
     
vector<int> inOrderTraversal(struct TreeNode* root) {
    vector<int> res;
    if(root == nullptr) return res;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true) {
        if(node != nullptr) {
            st.push(node);
            node = node->left;
        } else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            res.push_back(node->data);
            node = node->right;
        }
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
    vector<int>res = inOrderTraversal(root);
    cout << "In Order Traversal : " ;
    for(auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}