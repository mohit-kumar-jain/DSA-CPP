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
     
void inOrderTraversal(struct Node* root) {
    if(root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
                   
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "In Order Traversal : " ;
    inOrderTraversal(root);
    return 0;
}