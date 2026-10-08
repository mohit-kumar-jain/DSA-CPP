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
     
// T.C -> O(2N), S.C -> O(N).
vector<int> postOrderTraversal(struct TreeNode* root) {
    vector<int> res;
    if(root == nullptr) return res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr != NULL || !st.empty()) {
        if(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        } else{
            TreeNode* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                res.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->data);
                }
            }else{
                curr = temp;
            }
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
    vector<int>res = postOrderTraversal(root);
    cout << "In Order Traversal : " ;
    for(auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}