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
     
// T.C -> O(N), S.C -> O(2N).
// we are using 2 stacks.
vector<int> postOrderTraversal(struct TreeNode* root) {
    vector<int> res;
    if(root == nullptr) return res;
    stack<TreeNode*> st1,st2;
    st1.push(root);
    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr) {
            st1.push(root->left);
        }
        if(root->right != nullptr) {
            st1.push(root->right);
        }
    }
    while(!st2.empty()) {
        res.push_back(st2.top()->data);
        st2.pop();
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
    vector<int>res = postOrderTraversal(root);
    cout << "In Order Traversal : " ;
    for(auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}