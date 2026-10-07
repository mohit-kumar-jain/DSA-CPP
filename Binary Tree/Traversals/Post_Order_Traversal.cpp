#include<bits/stdc++.h>
using namespace std;
                   
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
     
void postOrderTraversal(struct Node* root) {
    if(root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
                   
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Post Order Traversal : " ;
    postOrderTraversal(root);
    return 0;
}