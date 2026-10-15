#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(TreeNode *root, vector<TreeNode *> &nodes)
{
    if (root == nullptr)
    {
        return;
    }
    nodes.push_back(root);
    preorder(root->left, nodes);
    preorder(root->right, nodes);
}

// T.C -> O(N), S.C -> O(N).
TreeNode *flatten(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    vector<TreeNode *> nodes;
    preorder(root, nodes);
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->left = nullptr;
        nodes[i]->right = nodes[i + 1];
    }
    nodes.back()->left = nullptr;
    nodes.back()->right = nullptr;
    return root;
}


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root = flatten(root);
    while (root != nullptr)
    {
        cout << root->val << " ";
        root = root->right;
    }
    return 0;
}